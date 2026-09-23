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
	int	fd;

	(void)config;
	if (!is_cub_file(filename))
	{
		write(2, "Error\nFile must end with .cub\n", 30);
		return (1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCannot open map\n", 22);
		return (1);
	}
	close(fd);
	return (0);
}
