/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushli <yushli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 18:12:16 by yushli            #+#    #+#             */
/*   Updated: 2026/09/26 19:55:57 by yushli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_walkable(t_game *game, float x, float y)
{
	int		col;
	int		row;
	char	cell;

	if (x < 0 || y < 0)
		return (0);
	col = (int)(x / BLOCK);
	row = (int)(y / BLOCK);
	if (row >= game->config.map_height)
		return (0);
	if (col >= (int)ft_strlen(game->config.map[row]))
		return (0);
	cell = game->config.map[row][col];
	return (cell == '0' || cell == 'N' || cell == 'S'
		|| cell == 'E' || cell == 'W');
}

static int	can_move(t_game *game, float x, float y)
{
	float	radius;

	radius = 8.0f;
	return (is_walkable(game, x - radius, y - radius)
		&& is_walkable(game, x + radius, y - radius)
		&& is_walkable(game, x - radius, y + radius)
		&& is_walkable(game, x + radius, y + radius));
}

static void	get_move_vector(t_player *player, float *dx, float *dy)
{
	float	forward;
	float	sideways;
	float	cos_angle;
	float	sin_angle;

	forward = player->key_up - player->key_down;
	sideways = player->key_right - player->key_left;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	*dx = forward * cos_angle - sideways * sin_angle;
	*dy = forward * sin_angle + sideways * cos_angle;
}

void	move_player(t_game *game)
{
	t_player	*player;
	float		dx;
	float		dy;

	player = &game->player;
	get_move_vector(player, &dx, &dy);
	if (dx != 0.0f && can_move(game, player->x + dx, player->y))
		player->x += dx;
	if (dy != 0.0f && can_move(game, player->x, player->y + dy))
		player->y += dy;
}
