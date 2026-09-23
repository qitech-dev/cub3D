/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:27:30 by qijin             #+#    #+#             */
/*   Updated: 2025/11/26 18:27:31 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_fmt(char type, va_list ap)
{
	char	*base1;
	char	*base2;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (type == 'c')
		return (ft_putchar_len_fd(va_arg(ap, int), 1));
	else if (type == 's')
		return (ft_putstr_len_fd(va_arg(ap, char *), 1));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr_len_fd(va_arg(ap, int), 1));
	else if (type == 'x')
		return (ft_putnbr_base_len(va_arg(ap, unsigned int), base1, 1));
	else if (type == 'X')
		return (ft_putnbr_base_len(va_arg(ap, unsigned int), base2, 1));
	else if (type == 'u')
		return (ft_putnbr_u_len(va_arg(ap, unsigned int), 1));
	else if (type == 'p')
		return (ft_putptr_len(va_arg(ap, void *)));
	else if (type == '%')
		return (ft_putchar_len_fd('%', 1));
	else
		return (-1);
}

static void	ft_deal_fmt(const char *format, va_list ap, int *i, int *total)
{
	char	type;
	int		len;

	type = format[*i + 1];
	len = ft_handle_fmt(type, ap);
	if (len == -1)
		*total += ft_putchar_len_fd('%', 1) + ft_putchar_len_fd(type, 1);
	else
		*total += len;
	if (type != '\0')
		(*i)++;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;
	int		i;

	va_start(ap, format);
	total = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			total += ft_putchar_len_fd((char)format[i], 1);
		else
			ft_deal_fmt(format, ap, &i, &total);
		i++;
	}
	va_end(ap);
	return (total);
}
