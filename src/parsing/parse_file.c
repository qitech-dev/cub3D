#include "cub3d.h"

static int	is_cub_file(char *filename)
{
	int	len;

	len = 0;
	while (filename[len])
		len++;
	if (len < 5)
		return (0);
	if (filename[len - 4] != '.'
		|| filename[len - 3] != 'c'
		|| filename[len - 2] != 'u'
		|| filename[len - 1] != 'b')
		return (0);
	return (1);
}

int	parse_file(char *filename, t_config *config)
{
	int				fd;
	char			*line;
	t_identifier	id;

	if (!is_cub_file(filename))
		return (parser_error("File must end with .cub"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (parser_error("Cannot open map"));
	line = get_next_line(fd);
	while (line)
	{
		id = parse_identifier(line);
		if (id == ID_NO || id == ID_SO
			|| id == ID_WE || id == ID_EA)
		{
			if (parse_texture(line, config, id))
			{
				free(line);
				close(fd);
				return (1);
			}
		}
		else if (id == ID_INVALID)
		{
			free(line);
			close(fd);
			return (parser_error("Invalid line"));
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
