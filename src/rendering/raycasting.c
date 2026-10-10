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

static float	fixed_distance(t_player *player, float ray_x, float ray_y)
{
	return ((ray_x - player->x) * cos(player->angle)
		+ (ray_y - player->y) * sin(player->angle));
}

static bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	if (px < 0 || py < 0)
		return (true);
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

void	draw_line(t_player *player, t_game *game, float start_x, int i)
{
	t_ray		ray;
	t_texture	*tex;
	t_wall		wall;

	ray.x = player->x;
	ray.y = player->y;
	ray.prev_x = ray.x;
	ray.prev_y = ray.y;
	ray.cos_angle = cos(start_x);
	ray.sin_angle = sin(start_x);
	while (!touch(ray.x, ray.y, game))
	{
		ray.prev_x = ray.x;
		ray.prev_y = ray.y;
		ray.x += ray.cos_angle;
		ray.y += ray.sin_angle;
	}
	wall.dist = fixed_distance(player, ray.x, ray.y);
	wall.screen_x = i;
	tex = get_hit_texture(game, &ray);
	wall.tex_x = get_texture_x(tex, ray.x, ray.y, ray.prev_x);
	draw_wall(game, tex, &wall);
}

void	cast_all_rays(t_game *game)
{
	float		fraction;
	float		ray_angle;
	int			screen_x;
	t_player	*player;

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
