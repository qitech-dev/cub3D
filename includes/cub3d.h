/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <qijin@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 19:57:07 by qijin             #+#    #+#             */
/*   Updated: 2026/10/01 19:57:08 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1280
# define HEIGHT 720
# define BLOCK 64

# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

# define PI 3.14159265358979323846

# include "./minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include <math.h>

typedef enum e_identifier
{
	ID_NO,
	ID_SO,
	ID_WE,
	ID_EA,
	ID_F,
	ID_C,
	ID_MAP,
	ID_EMPTY,
	ID_INVALID
}	t_identifier;

typedef struct s_config
{
	char	**map;
	int		map_width;
	int		map_height;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_color;
	int		ceiling_color;
	int		player_x;
	int		player_y;
	char	player_dir;
}	t_config;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_texture
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_textures
{
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;
	t_config	config;
	t_textures	textures;
}	t_game;

/* initialization */

void	init_config(t_config *config);

/* main parser */

int	parse_file(char *filename, t_config *config);

/* identifier */

t_identifier	parse_identifier(char *line);

/* textures / colors */

int	parse_texture(char *line, t_config *config, t_identifier id);
int	parse_color(char *line, t_config *config, t_identifier id);

/* map */

int	is_map_char(char c);
int	is_map_line(char *line);
int	add_map_line(t_config *config, char *line);

/* parser utils */

int		parser_error(char *message);
int		is_space(char c);
char	*skip_spaces(char *s);
int		is_empty_line(char *line);

/* validation */

int	validate_config(t_config *config);
int	validate_textures(t_config *config);
int	validate_player(t_config *config);
int	validate_closed_map(t_config *config);

/* cleanup */

void	free_config(t_config *config);

/*ray*/

void	put_pixel(int x, int y, int color, t_game *game);
void	cast_all_rays(t_game *game);

/*init*/

void	init_player(t_game *game);
void	init_game(t_game *game);

/*rendering*/

void	draw_line(t_player *player, t_game *game, float start_x, int i);
void	put_pixel(int x, int y, int color, t_game *game);

/*input*/

int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	move_player(t_player *player);
void	rotate_player(t_player *player);

/*cleanup*/

int		close_game(t_game *game);

#endif