#include "cub3d.h"

static int	match_two(char *s, char a, char b)
{
	return (
		s[0] == a
		&& s[1] == b
		&& is_space(s[2])
	);
}

static int	match_one(char *s, char a)
{
	return (
		s[0] == a
		&& is_space(s[1])
	);
}

t_identifier	parse_identifier(char *line)
{
	char	*s;

	if (is_empty_line(line))
		return (ID_EMPTY);
	s = skip_spaces(line);
	if (match_two(s, 'N', 'O'))
		return (ID_NO);
	if (match_two(s, 'S', 'O'))
		return (ID_SO);
	if (match_two(s, 'W', 'E'))
		return (ID_WE);
	if (match_two(s, 'E', 'A'))
		return (ID_EA);
	if (match_one(s, 'F'))
		return (ID_F);
	if (match_one(s, 'C'))
		return (ID_C);
	if (is_map_line(line))
		return (ID_MAP);
	return (ID_INVALID);
}
