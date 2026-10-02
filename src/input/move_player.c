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

void	move_player(t_player *player)
{
	int speed;
	float cos_angle;
	float sin_angle;

	speed = 1;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->key_up)
	{
		player->x += speed * cos_angle;
		player->y += speed * sin_angle;
	}
	if (player->key_down)
	{
		player->x -= speed * cos_angle;
		player->y -= speed * sin_angle;
	}
	if (player->key_left)
	{
		player->x += speed * sin_angle;
		player->y -= speed * cos_angle;
	}
	if (player->key_right)
	{
		player->x -= speed * sin_angle;
		player->y += speed * cos_angle;
	}
}