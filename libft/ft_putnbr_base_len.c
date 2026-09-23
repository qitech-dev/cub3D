/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:11:40 by qijin             #+#    #+#             */
/*   Updated: 2025/12/01 18:11:41 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_fd_long(long int nbr, char *base, int fd)
{
	char	c;
	int		len;

	len = 0;
	if (nbr >= 16)
		len = len + ft_putnbr_fd_long(nbr / 16, base, fd);
	c = base[nbr % 16];
	write(fd, &c, 1);
	return (len + 1);
}

int	ft_putnbr_base_len(unsigned int n, char *base, int fd)
{
	long int	nbr;
	int			len;

	nbr = n;
	len = 0;
	len = len + ft_putnbr_fd_long(nbr, base, fd);
	return (len);
}
