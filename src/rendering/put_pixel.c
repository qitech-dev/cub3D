/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushli <yushli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:15:01 by yushli            #+#    #+#             */
/*   Updated: 2026/09/26 19:15:41 by yushli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_pixel(int x, int y, int color, t_game *game)
{
    int index; // 目标像素在 data 数组中的起始字节位置
    
    if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return;
    index = (y * game->size_line) + (x * (game->bpp / 8));
    // y * size_line：跳过前面的 y 行，单位是字节
    // bpp / 8：一个像素占多少字节；例如 32 位像素占 4 字节
    // x * (bpp / 8)：跳过当前行前面的 x 个像素
    // 两部分相加，就到达坐标 (x, y) 对应像素的起始位置
    game->data[index] = (color & 0xFF);
    // 取 color 最低的 8 位，写入第一个字节；对常见 0xRRGGBB 颜色来说是蓝色 B
    game->data[index + 1] = (color >> 8) & 0xFF;
    // >> 8 表示向右移动 8 位，再取最低 8 位，得到绿色 G
    game->data[index + 2] = (color >> 16) & 0xFF;
    // >> 16 表示向右移动 16 位，再取最低 8 位，得到红色 R
}
/*下面是调试用*/
/*
void draw_square(int x, int y, int size, int color, t_game *game)
{
    for (int i = 0; i < size; i++)
        put_pixel(x + i, y, color, game);
     for (int i = 0; i < size; i++)
        put_pixel(x, y + i, color, game);
     for (int i = 0; i < size; i++)
        put_pixel(x + size, y + i, color, game);
     for (int i = 0; i < size; i++)
        put_pixel(x + i, y + size, color, game);

}
void draw_map(t_game *game)
{
    char **map;
    int color;

    map = game->map;
    color = 0x0000FF;
    for (int y = 0; map[y] != NULL; y++)
    {
        for (int x = 0; map[y][x] != '\0'; x++)
        {
            if (map[y][x] == '1')
                draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
        }
    }
}
*/