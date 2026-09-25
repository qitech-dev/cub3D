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
