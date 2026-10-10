/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_bytes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <qijin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 23:37:28 by qijin             #+#    #+#             */
/*   Updated: 2026/10/09 23:37:29 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	has_nul_byte(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (buffer[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	validate_file_bytes(char *filename)
{
	int		fd;
	ssize_t	bytes_read;
	char	buffer[1024];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (parser_error("Cannot open file"));
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		if (has_nul_byte(buffer, bytes_read))
		{
			close(fd);
			return (parser_error("NUL byte in scene file"));
		}
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	close(fd);
	if (bytes_read < 0)
		return (parser_error("Failed to read file"));
	return (0);
}
