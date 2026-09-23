/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:12:40 by qijin             #+#    #+#             */
/*   Updated: 2025/11/14 17:12:42 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t						i;
	const unsigned char			*ss;
	unsigned char				uc;

	ss = (const unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < size)
	{
		if (ss[i] == uc)
			return ((void *)(ss + i));
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main()
{
	char *s = "jdlsjaiednfa1221ask";
	char *ss = ft_memchr(s, 9, 18);
	printf("%s\n", ss);
	return 0;
}*/