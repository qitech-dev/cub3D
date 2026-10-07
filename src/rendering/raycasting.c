/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushli <yushli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 18:56:17 by yushli            #+#    #+#             */
/*   Updated: 2026/09/26 20:00:23 by yushli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** 根据 x 和 y 的差值计算直线距离。
*/
static float	distance(float dx, float dy)
{
	return (sqrt(dx * dx + dy * dy));
}

/*
** 把射线的实际距离投影到玩家正前方，
** 修正屏幕边缘产生的鱼眼畸变。
*/
static float	fixed_distance(float x1, float y1, float x2, float y2,
		t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle_diff;
	float	fixed_distance;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle_diff = atan2(delta_y, delta_x) - game->player.angle;
	fixed_distance = distance(delta_x, delta_y) * cos(angle_diff);
	return (fixed_distance);
}

/*
** 检查像素坐标 (px, py) 当前是否位于墙格子中。
*/
//注意这个函数可能越界，有必要之后修改
static bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (y < 0 || y >= game->config.map_height)
		return (true);
	if (x < 0 || x >= (int)ft_strlen(game->config.map[y]))
		return (true);
	if (game->config.map[y][x] == '1'
		|| game->config.map[y][x] == ' ')
		return (true);
	return (false);
}

/* 发射一条射线，找到墙壁并绘制对应的屏幕竖线。*/
void	draw_line(t_player *player, t_game *game, float start_x, int i)
{
	float	ray_x;
	float	ray_y;
	float	cos_angle;
	float	sin_angle;
	float	dist;

	ray_x = player->x;
	ray_y = player->y;
	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	while (!touch(ray_x, ray_y, game))
	{
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	dist = fixed_distance(player->x, player->y, ray_x, ray_y, game);
}

/*
** 遍历屏幕的全部竖列，每一列发射一条射线。
**
** 这是 raycasting.c 唯一向其他文件开放的函数。
*/
void	cast_all_rays(t_game *game)
{
	float fraction;
	float ray_angle;
	int screen_x;
	t_player *player;

	player = &game->player;
	fraction = PI / 3 / WIDTH;
	ray_angle = player->angle - (PI / 6);
	screen_x = 0;
	while (screen_x < WIDTH)
	{
		draw_line(player, game, ray_angle, screen_x);
		ray_angle += fraction;
		screen_x++;
	}
}