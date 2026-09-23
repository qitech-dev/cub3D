/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:45:23 by qijin             #+#    #+#             */
/*   Updated: 2025/11/26 13:45:26 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(long int res, int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	if (res == 0)
		return (1);
	while (res > 0)
	{
		res = res / 10;
		len++;
	}
	return (len);
}

static char	*ft_special(long int res, char *str)
{
	if (res == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long int	res;
	char		*str;
	int			len;
	int			l;

	res = n;
	if (n < 0)
		res *= -1;
	len = ft_get_len(res, n);
	l = len;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (res == 0)
		return (ft_special(res, str));
	while (len > 0 && res > 0)
	{
		str[len - 1] = '0' + (res % 10);
		res = res / 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	str[l] = '\0';
	return (str);
}
