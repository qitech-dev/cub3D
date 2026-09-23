/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:23:36 by qijin             #+#    #+#             */
/*   Updated: 2025/12/01 21:23:38 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_len(unsigned long p, char *base)
{
	int				len;
	unsigned long	base_len;

	len = 0;
	base_len = 16;
	if (p >= base_len)
		len = len + ft_puthex_len(p / base_len, base);
	ft_putchar_len_fd(base[p % base_len], 1);
	return (len + 1);
}

int	ft_putptr_len(void *ptr)
{
	unsigned long	p;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	p = (unsigned long)ptr;
	write(1, "0x", 2);
	return (2 + ft_puthex_len(p, "0123456789abcdef"));
}
