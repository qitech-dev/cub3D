/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushli <yushli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 18:43:55 by yushli            #+#    #+#             */
/*   Updated: 2026/09/26 19:49:29 by yushli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx_values(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->data = NULL;
	game->bpp = 0;
	game->size_line = 0;
	game->endian = 0;
}

static void	init_error(t_game *game, char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_config(&game->config);
	exit(1);
}

void	init_game(t_game *game)
{
	init_mlx_values(game);
	init_player(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		init_error(game, "Failed to initialize MiniLibx");
	if (load_textures(game))
		init_error(game, "Failed to load textures");
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		init_error(game, "Failed to create a window");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		init_error(game, "Failed to create a image");
	game->data = mlx_get_data_addr(game->img, &game->bpp,
			&game->size_line, &game->endian);
	if (!game->data)
		init_error(game, "Failed to get image data");
}
