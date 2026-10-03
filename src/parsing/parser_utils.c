/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <qijin@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 17:10:47 by qijin             #+#    #+#             */
/*   Updated: 2026/10/03 17:10:48 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	validate_config(t_config *config)
{
	if (!config->no || !config->so || !config->we || !config->ea)
		return (parser_error("Missing texture"));
	if (config->floor_color == -1 || config->ceiling_color == -1)
		return (parser_error("Missing color"));
	if (!config->map || config->map_height == 0)
		return (parser_error("Missing map"));
	return (0);
}
