#include "cub3d.h"

static int  load_one_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path,
		&tex->width, &tex->height);
	if (!tex->img)
		return (1);
	tex->data = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->data)
		return (1);
	return (0);
}

int	load_textures(t_game *game)
{
	if (load_one_texture(game, &game->textures.no, game->config.no))
		return (1);
	if (load_one_texture(game, &game->textures.so, game->config.so))
		return (1);
	if (load_one_texture(game, &game->textures.we, game->config.we))
		return (1);
	if (load_one_texture(game, &game->textures.ea, game->config.ea))
		return (1);
	return (0);
}
