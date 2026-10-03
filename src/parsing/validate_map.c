/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <qijin@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 17:11:21 by qijin             #+#    #+#             */
/*   Updated: 2026/10/03 17:11:35 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	get_map_char(t_config *config, int y, int x)
{
	if (y < 0 || y >= config->map_height || x < 0)
		return (' ');
	if (x >= (int)ft_strlen(config->map[y]))
		return (' ');
	return (config->map[y][x]);
}

static int	set_player(t_config *config, int x, int y)
{
	char	c;

	c = config->map[y][x];
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (0);
	if (config->player_dir)
		return (parser_error("Multiple players"));
	config->player_x = x;
	config->player_y = y;
	config->player_dir = c;
	return (0);
}

int	validate_player(t_config *config)
{
	int	x;
	int	y;

	y = 0;
	while (config->map[y])
	{
		x = 0;
		while (config->map[y][x])
		{
			if (set_player(config, x, y))
				return (1);
			x++;
		}
		y++;
	}
	if (!config->player_dir)
		return (parser_error("Missing player"));
	return (0);
}

static int	cell_is_open(t_config *config, int y, int x)
{
	char	c;

	c = config->map[y][x];
	if (c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (0);
	if (get_map_char(config, y - 1, x) == ' '
		|| get_map_char(config, y + 1, x) == ' '
		|| get_map_char(config, y, x - 1) == ' '
		|| get_map_char(config, y, x + 1) == ' ')
		return (1);
	return (0);
}

int	validate_closed_map(t_config *config)
{
	int	x;
	int	y;

	y = 0;
	while (y < config->map_height)
	{
		x = 0;
		while (config->map[y][x])
		{
			if (cell_is_open(config, y, x))
				return (parser_error("Map is not closed"));
			x++;
		}
		y++;
	}
	return (0);
}
