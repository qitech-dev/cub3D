#include "cub3d.h"

static int	parse_number(char **s, int *value)
{
	int	n;

	n = 0;
	while (is_space(**s))
		(*s)++;
	if (**s < '0' || **s > '9')
		return (1);
	while (**s >= '0' && **s <= '9')
	{
		n = n * 10 + (**s - '0');
		if (n > 255)
			return (1);
		(*s)++;
	}
	while (is_space(**s))
		(*s)++;
	*value = n;
	return (0);
}

static int	parse_rgb(char *s, int *color)
{
	int	r;
	int	g;
	int	b;

	if (parse_number(&s, &r) || *s != ',')
		return (1);
	s++;
	if (parse_number(&s, &g) || *s != ',')
		return (1);
	s++;
	if (parse_number(&s, &b))
		return (1);
	while (is_space(*s))
		s++;
	if (*s == '\n')
		s++;
	if (*s != '\0')
		return (1);
	*color = (r << 16) | (g << 8) | b;
	return (0);
}

int	parse_color(char *line, t_config *config, t_identifier id)
{
	int		*slot;
	char	*s;

	if (id == ID_F)
		slot = &config->floor_color;
	else if (id == ID_C)
		slot = &config->ceiling_color;
	else
		return (parser_error("Invalid color identifier"));
	if (*slot != -1)
		return (parser_error("Duplicate color"));
	s = skip_spaces(line);
	s++;
	s = skip_spaces(s);
	if (parse_rgb(s, slot))
		return (parser_error("Invalid color"));
	return (0);
}
