#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

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

int				check_args(int argc, char **argv);
int				parse_file(char *filename, t_config *config);
int				parser_error(char *message);
int				is_space(char c);
char			*skip_spaces(char *s);
int				is_empty_line(char *line);
int				is_map_char(char c);
int				is_map_line(char *line);
t_identifier	parse_identifier(char *line);

#endif