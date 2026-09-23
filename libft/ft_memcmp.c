/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:30:49 by qijin             #+#    #+#             */
/*   Updated: 2025/11/15 15:30:51 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
			return ((int)(cs1[i] - cs2[i]));
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int main()
{
    printf("%d\n", ft_memcmp("1234", "1234", 2));
    printf("%d\n", ft_memcmp("123456", "123jf", 9));
    printf("%d\n", ft_memcmp("abcdehf", "kasinasd2334", 1));
    return 0;
}*/