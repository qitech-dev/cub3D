/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:26:38 by qijin             #+#    #+#             */
/*   Updated: 2025/11/11 19:26:40 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*fil(unsigned char *d, const unsigned char *s, int size)
{
	int	i;

	if (d < s)
	{
		i = 0;
		while (i < size)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = size - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (d);
}

void	*ft_memmove(void *dest, const void *src, int size)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == src || size <= 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	d = fil(d, s, size);
	return (dest);
}
