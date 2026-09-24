#include "cub3d.h"

static char	**get_texture_slot(t_config *config, t_identifier id)
{
	if (id == ID_NO)
		return (&config->no);
	if (id == ID_SO)
		return (&config->so);
	if (id == ID_WE)
		return (&config->we);
	if (id == ID_EA)
		return (&config->ea);
	return (NULL);
}