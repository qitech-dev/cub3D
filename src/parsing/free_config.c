#include "cub3d.h"

static void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_config(t_config *config)
{
	free(config->no);
	free(config->so);
	free(config->we);
	free(config->ea);
	free_map(config->map);
	config->no = NULL;
	config->so = NULL;
	config->we = NULL;
	config->ea = NULL;
	config->map = NULL;
}
