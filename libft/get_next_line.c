/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:43:28 by qijin             #+#    #+#             */
/*   Updated: 2025/12/05 15:43:30 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	if (!s)
		return (NULL);
	uc = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*read_from_file(char *basin_buffer, int fd)
{
	int		bytes_read;
	char	*cup_buffer;
	char	*temp;

	cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(cup_buffer), free(basin_buffer), NULL);
		if (bytes_read == 0)
			break ;
		cup_buffer[bytes_read] = '\0';
		temp = ft_strjoin(basin_buffer, cup_buffer);
		if (!temp)
			return (free(cup_buffer), free(basin_buffer), NULL);
		free(basin_buffer);
		basin_buffer = temp;
		if (ft_strchr(basin_buffer, '\n'))
			break ;
	}
	return (free(cup_buffer), basin_buffer);
}

char	*extact_line(char *basin_buffer)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	while (basin_buffer[len] && basin_buffer[len] != '\n')
		len++;
	line = malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = basin_buffer[i];
		i++;
	}
	if (basin_buffer[len] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*obtain_remaining(char *basin_buffer)
{
	char	*new;
	size_t	i;
	size_t	len;
	size_t	rest;

	len = 0;
	while (basin_buffer[len] && basin_buffer[len] != '\n')
		len++;
	if (basin_buffer[len] == '\0')
		return (free(basin_buffer), NULL);
	rest = ft_strlen(basin_buffer) - len - 1;
	if (rest == 0)
		return (free(basin_buffer), NULL);
	new = malloc((rest + 1) * sizeof(char));
	if (!new)
		return (free(basin_buffer), NULL);
	i = 0;
	while (i < rest)
	{
		new[i] = basin_buffer[len + 1 + i];
		i++;
	}
	new[i] = '\0';
	return (free(basin_buffer), new);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer;
	char		*line;
	char		*temp;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basin_buffer)
		basin_buffer = ft_calloc(1, sizeof(char));
	if (!basin_buffer)
		return (NULL);
	if (!ft_strchr(basin_buffer, '\n'))
		basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer)
		return (NULL);
	if (basin_buffer[0] == '\0')
		return (free(basin_buffer), basin_buffer = NULL, NULL);
	line = extact_line(basin_buffer);
	if (!line)
		return (NULL);
	temp = obtain_remaining(basin_buffer);
	if (!temp)
		return (basin_buffer = NULL, line);
	basin_buffer = temp;
	return (line);
}
