/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushli <yushli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:31:48 by yushli            #+#    #+#             */
/*   Updated: 2026/09/26 19:49:21 by yushli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_game_images(t_game *game)
{
	if (game->textures.no.img)
		mlx_destroy_image(game->mlx, game->textures.no.img);
	if (game->textures.so.img)
		mlx_destroy_image(game->mlx, game->textures.so.img);
	if (game->textures.we.img)
		mlx_destroy_image(game->mlx, game->textures.we.img);
	if (game->textures.ea.img)
		mlx_destroy_image(game->mlx, game->textures.ea.img);
	if (game->img)
	{
		mlx_destroy_image(game->mlx, game->img);
		game->img = NULL;
	}
}

static void	destroy_game_mlx(t_game *game)
{
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

int	close_game(t_game *game)
{
	destroy_game_images(game);
	destroy_game_mlx(game);
	free_config(&game->config);
	exit(0);
	return (0);
}
