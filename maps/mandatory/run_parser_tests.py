#!/usr/bin/env python3
"""Check scene parsing without opening a window or changing project files."""

import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shlex
import subprocess
import sys
import tempfile


SUITE = Path(__file__).resolve().parent
ROOT = SUITE.parent.parent
HARNESS = r'''#include "cub3d.h"

int main(int argc, char **argv)
{
    t_config config;
    int result;
    int row;

    if (argc != 2)
        return (2);
    init_config(&config);
    result = parse_file(argv[1], &config);
    if (!result)
    {
        printf("OK %d %d %d %d %c %d %d\n", config.map_width,
            config.map_height, config.player_x, config.player_y,
            config.player_dir, config.floor_color, config.ceiling_color);
        printf("%s\n%s\n%s\n%s\n", config.no, config.so, config.we, config.ea);
        row = 0;
        while (config.map[row])
            printf("%s\n", config.map[row++]);
    }
    free_config(&config);
    return (result != 0);
}
'''


def command(arguments, directory):
    subprocess.run(arguments, cwd=directory, check=True, capture_output=True,
                   timeout=60)


def build_harness(directory):
    compiler = shlex.split(os.environ.get('CC', 'cc'))
    flags = ['-Wall', '-Wextra', '-Werror', '-ffunction-sections',
             '-fdata-sections', '-I' + str(ROOT / 'includes'),
             '-I' + str(ROOT / 'libft')]
    makefile = (ROOT / 'libft/Makefile').read_text().replace('\\\n', ' ')
    match = re.search(r'^SOURCES\s*=\s*(.+)$', makefile, re.MULTILINE)
    if match is None:
        raise ValueError('Could not find the libft SOURCES list.')
    library_sources = shlex.split(match.group(1))
    if not library_sources or any(not name.endswith('.c') for name in library_sources):
        raise ValueError('Expected explicit .c paths in the libft SOURCES list.')
    library_paths = [str(ROOT / 'libft' / name) for name in library_sources]
    command(compiler + flags + ['-c'] + library_paths, directory)
    library_objects = [str(directory / (Path(name).stem + '.o'))
                       for name in library_sources]
    archive = directory / 'libft.a'
    command(['ar', 'rcs', str(archive)] + library_objects, directory)

    parser_sources = sorted((ROOT / 'src/parsing').glob('*.c'))
    command(compiler + flags + ['-c'] + [str(path) for path in parser_sources], directory)
    # Keep the project's actual init_config(); discard its graphical entry point.
    command(compiler + flags + ['-Dmain=cub3d_application_main', '-c',
                               str(ROOT / 'src/main.c'), '-o', str(directory / 'main.o')],
            directory)
    harness_source = directory / 'parser_harness.c'
    harness_source.write_text(HARNESS)
    executable = directory / 'parser_tests'
    parser_objects = [str(directory / (path.stem + '.o')) for path in parser_sources]
    command(compiler + flags + ['-Wl,--gc-sections', str(harness_source),
                               str(directory / 'main.o')] + parser_objects
            + [str(archive), '-o', str(executable)], directory)
    return executable


def check_case(executable, case):
    try:
        result = subprocess.run([str(executable), str(SUITE / case['path'])],
                                cwd=ROOT, capture_output=True, timeout=5)
    except subprocess.TimeoutExpired:
        return 'parser did not finish within 5 seconds'
    if case['kind'] == 'reject':
        if result.returncode != 1:
            return f'expected clean rejection (exit 1), got exit {result.returncode}'
        if not result.stderr.startswith(b'Error\n') or not result.stderr[6:].strip():
            return 'expected Error followed by an explicit message on stderr'
        if result.stdout:
            return 'rejected input unexpectedly produced a parsed configuration'
        return None
    if result.returncode != 0:
        return f'expected parser acceptance, got exit {result.returncode}: ' + \
            result.stderr.decode(errors='replace').strip()
    if result.stderr:
        return 'accepted input unexpectedly wrote to stderr'
    sections = result.stdout.split(b'\n', 5)
    if len(sections) != 6:
        return 'incomplete parsed configuration output'
    expected = case['expected_config']
    header = 'OK {width} {height} {player_x} {player_y} {player_dir} ' \
             '{floor_color} {ceiling_color}'.format(**expected).encode()
    if sections[0] != header:
        return 'map dimensions, player spawn, or RGB values differ from the fixture'
    if sections[1:5] != [path.encode() for path in expected['textures']]:
        return 'texture paths were not preserved correctly'
    if hashlib.sha256(sections[5]).hexdigest() != expected['map_sha256']:
        return 'map rows or their leading/trailing spaces were changed'
    return None


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--case', default='', help='only test paths containing this text')
    parser.add_argument('--list', action='store_true', help='list selected cases without compiling')
    arguments = parser.parse_args()
    cases = json.loads((SUITE / 'cases.json').read_text())['cases']
    cases = [case for case in cases if arguments.case in case['path']]
    if not cases:
        parser.error('no cases match --case')
    if arguments.list:
        for case in cases:
            print(f"{case['kind']:10} {case['path']}: {case['description']}")
        return 0
    failures = []
    try:
        with tempfile.TemporaryDirectory(prefix='cub3d-parser-', dir='/tmp') as temporary:
            executable = build_harness(Path(temporary))
            for case in cases:
                problem = check_case(executable, case)
                if problem:
                    failures.append(case['path'])
                    print(f"FAIL {case['path']}: {problem}")
    except (OSError, ValueError, subprocess.TimeoutExpired, subprocess.CalledProcessError) as error:
        print(f'Could not build or run the parser harness: {error}', file=sys.stderr)
        if isinstance(error, subprocess.CalledProcessError):
            print(error.stderr.decode(errors='replace'), file=sys.stderr)
        return 2
    print(f'{len(cases) - len(failures)}/{len(cases)} parser expectations matched.')
    load_cases = sum(case['kind'] == 'load_error' for case in cases)
    if load_cases:
        print(f'{load_cases} texture-load error cases were checked only for parser acceptance; '
              'image loading requires a separate graphical run.')
    print('Window events, rendering, and memory leaks were not checked by this runner.')
    return int(bool(failures))


if __name__ == '__main__':
    sys.exit(main())
