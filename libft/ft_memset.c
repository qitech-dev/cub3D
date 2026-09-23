/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:25:59 by qijin             #+#    #+#             */
/*   Updated: 2025/11/10 19:26:00 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, int size)
{
	unsigned char	*p;
	int				i;

	p = (unsigned char *)str;
	i = 0;
	while (i < size)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
