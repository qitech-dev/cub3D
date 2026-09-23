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
