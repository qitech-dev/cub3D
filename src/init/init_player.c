/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushli <yushli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 18:26:41 by yushli            #+#    #+#             */
/*   Updated: 2026/09/26 19:50:50 by yushli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->player.x = (game->config.player_x + 0.5) * BLOCK;
	game->player.y = (game->config.player_y + 0.5) * BLOCK;
	if (game->config.player_dir == 'E')
		game->player.angle = 0;
	else if (game->config.player_dir == 'S')
		game->player.angle = PI /2;
	else if (game->config.player_dir == 'W')
		game->player.angle = PI;
	else if (game->config.player_dir == 'N')
		game->player.angle = 3 * PI / 2;
	game->player.key_up = false;
	game->player.key_down = false;
	game->player.key_left = false;
	game->player.key_right = false;
	game->player.left_rotate = false;
	game->player.right_rotate = false;
}
