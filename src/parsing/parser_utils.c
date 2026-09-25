#include "cub3d.h"

int	parser_error(char *message)
{
	write(2, "Error\n", 6);
	if (message)
	{
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
	}
	return (1);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

char	*skip_spaces(char *s)
{
	while (*s && is_space(*s))
		s++;
	return (s);
}

int	is_empty_line(char *line)
{
	char	*s;

	s = skip_spaces(line);
	return (*s == '\n' || *s == '\0');
}
