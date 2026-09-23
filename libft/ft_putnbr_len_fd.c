/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:12:21 by qijin             #+#    #+#             */
/*   Updated: 2025/11/26 15:12:22 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_fd_long(long int nbr, int fd)
{
	char	c;
	int		len;

	len = 0;
	if (nbr >= 10)
		len = len + ft_putnbr_fd_long(nbr / 10, fd);
	c = (char)('0' + (nbr % 10));
	write(fd, &c, 1);
	return (len + 1);
}

int	ft_putnbr_len_fd(int n, int fd)
{
	long int	nbr;
	int			len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
		len++;
	}
	len = len + ft_putnbr_fd_long(nbr, fd);
	return (len);
}
