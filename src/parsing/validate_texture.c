#include "cub3d.h"

static int	texture_exists(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	validate_textures(t_config *config)
{
	if (!texture_exists(config->no))
		return (parser_error("Invalid NO texture path"));
	if (!texture_exists(config->so))
		return (parser_error("Invalid SO texture path"));
	if (!texture_exists(config->we))
		return (parser_error("Invalid WE texture path"));
	if (!texture_exists(config->ea))
		return (parser_error("Invalid EA texture path"));
	return (0);
}
