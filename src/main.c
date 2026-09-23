#include "cub3d.h"

static void	init_config(t_config *config)
{
	config->no = NULL;
	config->so = NULL;
	config->we = NULL;
	config->ea = NULL;
	config->floor_color = -1;
	config->ceiling_color = -1;
	config->map = NULL;
	config->map_width = 0;
	config->map_height = 0;
	config->player_x = -1;
	config->player_y = -1;
	config->player_dir = 0;
}

int	main(int argc, char **argv)
{
	t_config	config;

	init_config(&config);
	if (argc != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 34);
		return (1);
	}
	if (parse_file(argv[1], &config) != 0)
		return (1);
	return (0);
}
