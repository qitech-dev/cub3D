#include "cub3d.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'S'
		|| c == 'E' || c == 'W');
}

static int	map_line_len(char *line)
{
	int	len;

	len = 0;
	while (line[len])
		len++;
	return (len);	
}

static char	get_map_char(t_config *config, int x, int y)
{
	int	len;

	if (y < 0 || y >= config->map_height)
		return (' ');
	if (x < 0)
		return (' ');
	len = map_line_len(config->map[y]);
	if (x >= len)
		return (' ');
	return (config->map[y][x]);
}

int	validate_player(t_config *config)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (config->map[y])
	{
		x = 0;
		while (config->map[y][x])
		{
			if (is_player(config->map[y][x]))
			{
				count++;
				config->player_x = x;
				config->player_y = y;
				config->player_dir = config->map[y][x];
			}
			x++;
		}
		y++;
	}
	if (count == 0)
		return (parser_error("Missing player"));
	if (count > 1)
		return (parser_error("Multiple players"));
	return (0);
}


