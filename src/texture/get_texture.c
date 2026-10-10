/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <qijin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 23:31:54 by qijin             #+#    #+#             */
/*   Updated: 2026/10/09 23:31:56 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_hit_texture(t_game *game,
		float ray_x, float ray_y, float prev_x, float prev_y)
{
	int	old_x;
	int	old_y;
	int	new_x;
	int	new_y;

	old_x = (int)(prev_x / BLOCK);
	old_y = (int)(prev_y / BLOCK);
	new_x = (int)(ray_x / BLOCK);
	new_y = (int)(ray_y / BLOCK);
	if (new_x != old_x)
	{
		if (ray_x > prev_x)
			return (&game->textures.we);
		return (&game->textures.ea);
	}
	if (new_y != old_y)
	{
		if (ray_y > prev_y)
			return (&game->textures.no);
		return (&game->textures.so);
	}
	return (&game->textures.no);
}

int	get_texture_x(t_texture *tex,
		float ray_x, float ray_y, float prev_x)
{
	float	offset;
	int		tex_x;

	if ((int)(prev_x / BLOCK) != (int)(ray_x / BLOCK))
		offset = fmod(ray_y, BLOCK) / BLOCK;
	else
		offset = fmod(ray_x, BLOCK) / BLOCK;
	tex_x = (int)(offset * tex->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	return (tex_x);
}

int	get_texture_pixel(t_texture *tex, int x, int y)
{
	char			*pixel;
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;

	pixel = tex->data + y * tex->line_len + x * (tex->bpp / 8);
	b = (unsigned)pixel[0];
	g = (unsigned)pixel[1];
	r = (unsigned)pixel[2];
	return ((r << 16) | (g << 8) | b);
}
