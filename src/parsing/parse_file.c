/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <qijin@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 19:58:01 by qijin             #+#    #+#             */
/*   Updated: 2026/10/01 19:58:03 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_cub_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (filename[len - 4] != '.' || filename[len - 3] != 'c'
		|| filename[len - 2] != 'u' || filename[len - 1] != 'b')
		return (0);
	return (1);
}

static int	handle_map(t_config *config, char *line, int *state)
{
	if (state[1])
		return (parser_error("Map interrupted by empty line"));
	state[0] = 1;
	return (add_map_line(config, line));
}

static int	handle_line(t_config *config, char *line, int *state)
{
	t_identifier	id;

	id = parse_identifier(line);
	if (id == ID_MAP)
		return (handle_map(config, line, state));
	if (id == ID_EMPTY)
	{
		if (state[0])
			state[1] = 1;
		return (0);
	}
	if (state[0])
		return (parser_error("Map must be last"));
	if (id == ID_NO || id == ID_SO || id == ID_WE || id == ID_EA)
		return (parse_texture(line, config, id));
	if (id == ID_F || id == ID_C)
		return (parse_color(line, config, id));
	return (parser_error("Invalid line"));
}

static int	read_file(int fd, t_config *config)
{
	char	*line;
	int		state[2];

	state[0] = 0;
	state[1] = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (handle_line(config, line, state))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	parse_file(char *filename, t_config *config)
{
	int	fd;

	if (!is_cub_file(filename))
		return (parser_error("File must end with .cub"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (parser_error("Cannot open map"));
	if (read_file(fd, config))
	{
		close(fd);
		return (1);
	}
	close(fd);
	if (validate_config(config) || validate_textures(config)
		|| validate_player(config) || validate_closed_map(config))
		return (1);
	return (0);
}
