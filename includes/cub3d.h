#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	char	player_dir;
}	t_config;

int		check_args(int argc, char **argv);
int		parse_file(char *filename, t_config *config);

#endif