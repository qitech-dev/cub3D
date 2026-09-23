/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:10:09 by qijin             #+#    #+#             */
/*   Updated: 2025/11/14 15:10:10 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	uc;

	len = ft_strlen(s);
	uc = (unsigned char)c;
	while (len >= 0)
	{
		if ((unsigned char)(s[len]) == uc)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main()
{
	char *s = "kaksjfsdg12414fkdhjf";
	printf("%s\n", ft_strrchr(s, 49));
	return 0;
}*/