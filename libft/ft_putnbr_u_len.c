/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:17:29 by qijin             #+#    #+#             */
/*   Updated: 2025/12/01 19:17:31 by qijin            ###   ########.fr       */
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

int	ft_putnbr_u_len(unsigned int n, int fd)
{
	long int	nbr;
	int			len;

	nbr = n;
	len = 0;
	len = len + ft_putnbr_fd_long(nbr, fd);
	return (len);
}
