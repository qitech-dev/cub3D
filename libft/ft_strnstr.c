/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:11:23 by qijin             #+#    #+#             */
/*   Updated: 2025/11/15 16:11:27 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			n = 0;
			while (i + n < len && little[n] != '\0' && big[i + n] == little[n])
				n++;
			if (little[n] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main()
{
	printf("%s\n", ft_strnstr("osdifh289af237hfdksad8934dh", "37hfd", 7));
	printf("%s\n", ft_strnstr("osdifh289af237hfdksad8934dh", "37hfd", 28));
	printf("%s\n", ft_strnstr("osdifh289af237hfdksad8934dh", "37hd", 28));
	printf("%s\n", ft_strnstr("osdifh289af237hfdksad8934dh", "37hd", 7));
	return (0);
}*/