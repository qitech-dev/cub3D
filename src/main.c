#include "cub3d.h"

void	init_config(t_config *config)
{
	config->no = NULL;
	config->so = NULL;
	config->we = NULL;
	config->ea = NULL;
	config->floor_color = -1;
	config->ceiling_color = -1;
	config->map = NULL;
	config->map_width = 0;
	config->map_height = 0;
	config->player_x = -1;
	config->player_y = -1;
	config->player_dir = 0;
}

void	clear_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_pixel(x, y, game->config.ceiling_color, game);
			else
				put_pixel(x, y, game->config.floor_color, game);
			x++;
		}
		y++;
	}
}

int	draw_loop(t_game *game)
{
	rotate_player(&game->player);
	move_player(&game->player);
	clear_image(game);
	cast_all_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_config(&game.config);
	if (argc != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 34);
		free_config(&game.config);
		return (1);
	}
	if (parse_file(argv[1], &game.config))
	{
		free_config(&game.config);
		return (1);
	}
	init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
