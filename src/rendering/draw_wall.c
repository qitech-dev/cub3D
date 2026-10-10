/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <qijin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 23:09:18 by qijin             #+#    #+#             */
/*   Updated: 2026/10/09 23:09:21 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_game *game, t_texture *tex, t_wall *wall)
{
	int	wall_height;
	int	draw_start;
	int	draw_end;
	int	y;
	int	tex_y;

	wall_height = (BLOCK / wall->dist) * (WIDTH / 2);
	if (wall_height < 1)
		wall_height = 1;
	draw_start = HEIGHT / 2 - wall_height / 2;
	draw_end = draw_start + wall_height;
	y = draw_start;
	if (y < 0)
		y = 0;
	if (draw_end > HEIGHT)
		draw_end = HEIGHT;
	while (y < draw_end)
	{
		tex_y = (y - draw_start) * tex->height / wall_height;
		put_pixel(wall->screen_x, y,
			get_texture_pixel(tex, wall->tex_x, tex_y), game);
		y++;
	}
}
