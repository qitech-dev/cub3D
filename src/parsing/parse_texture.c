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

static char	*skip_identifier(char *line, t_identifier id)
{
	char	*s;

	s = skip_spaces(line);
	if (id == ID_NO || id == ID_SO || id == ID_WE || id == ID_EA)
		s += 2;
	return (skip_spaces(s));
}

int	parse_texture(char *line, t_config *config, t_identifier id)
{
	char	**slot;
	char	*path;
	int		len;

	slot = get_texture_slot(config, id);
	if (!slot)
		return (parser_error("Invalid texture identifier"));
	if (*slot)
		return (parser_error("Duplicate texture"));
	path = skip_identifier(line, id);
	len = 0;
	while (path[len] && path[len] != '\n')
		len++;
	while (len > 0 && is_space(path[len - 1]))
		len--;
	if (len == 0)
		return (parser_error("Missing texture path"));
	*slot = ft_substr(path, 0, len);
	if (!*slot)
		return (parser_error("Malloc failed"));
	return (0);
}
