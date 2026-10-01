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

#include "../../includes/cub3d.h"

char	**get_map(void)
{
	static char	*map[] = {"11111111111111111111", "10000000000000000001",
			"10000000000000000001", "10000000000000000001",
			"10000001111111000001", "10000001000001000001",
			"10000001000001000001", "10000001000001000001",
			"10000001111111000001", "10000000000000000001",
			"10000000000000000001", "11111111111111111111", NULL};

	return (map);
}

void	init_game(t_game *game)
{
	init_player(&game->player); // 初始化玩家位置和按键状态
	game->map = get_map();      // 获取地图数据
	game->mlx = mlx_init();     // 初始化 MiniLibX，取得图形连接指针
	if (!game->mlx)
	{
		fprintf(stderr, "Failed to initialize MiniLibX\n");
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
	// 使用图形连接创建窗口：宽 WIDTH，高 HEIGHT，标题为 "Game"
	if (!game->win)
	{
		fprintf(stderr, "Failed to create window\n");
		exit(EXIT_FAILURE);
	}
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	// 创建一张与窗口一样大的内存图像；此时还没有把它显示到窗口
	if (!game->img)
	{
		fprintf(stderr, "Failed to create image\n");
		exit(EXIT_FAILURE);
	}
	game->data = mlx_get_data_addr(game->img,        // 要获取数据的图像
									&game->bpp,       // 函数通过这个地址写入每个像素的位数
									&game->size_line, // 函数通过这个地址写入每行的字节数
									&game->endian     // 函数通过这个地址写入字节顺序信息
	);
	// 返回值是图像像素数据的起始地址，保存在 game->data 中
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	// 将当前图像显示到窗口，图像左上角放在窗口坐标 (0, 0)
}
