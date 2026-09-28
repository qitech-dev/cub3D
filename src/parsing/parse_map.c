#include "cub3d.h"

int	is_map_char(char c)
{
	return (
		c == '0'
		|| c == '1'
		|| c == 'N'
		|| c == 'S'
		|| c == 'E'
		|| c == 'W'
		|| c == ' '
	);
}

int	is_map_line(char *line)
{
	int	i;
	int	has_real_char;

	i = 0;
	has_real_char = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!is_map_char(line[i]))
			return (0);
		if (line[i] != ' ')
			has_real_char = 1;
		i++;
	}
	return (has_real_char);
}

static char	*copy_map_line(char *line)
{
	int		len;
	char	*copy;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	len = 0;
	while (line[len] && line[len] != '\n')
	{
		copy[len] = line[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}

int	add_map_line(t_config *config, char *line)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (config->map_height + 2));
	if (!new_map)
		return (parser_error("Malloc failed"));
	i = 0;
	while (i < config->map_height)
	{
		new_map[i] = config->map[i];
		i++;
	}
	new_map[i] = copy_map_line(line);
	if (!new_map[i])
	{
		free(new_map);
		return (parser_error("Malloc failed"));
	}
	new_map[i + 1] = NULL;
	free(config->map);
	config->map = new_map;
	config->map_height++;
	return (0);
}
