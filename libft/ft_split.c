/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:34:12 by qijin             #+#    #+#             */
/*   Updated: 2025/11/25 21:34:14 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_c(char a, char c)
{
	if (a == c)
		return (1);
	else
		return (0);
}

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && ft_is_c(s[i], c) == 1)
			i++;
		if (s[i] && ft_is_c(s[i], c) == 0)
			count++;
		while (s[i] && ft_is_c(s[i], c) == 0)
			i++;
	}
	return (count);
}

static void	*ft_free_all(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**ft_fill_str(char **str, int count, const char *s, char c)
{
	int	i;
	int	n;
	int	len;

	i = 0;
	n = 0;
	while (n < count)
	{
		while (s[i] && ft_is_c(s[i], c) == 1)
			i++;
		len = 0;
		while (s[i + len] && ft_is_c(s[i + len], c) == 0)
			len++;
		str[n] = ft_substr(s, i, len);
		if (!str[n])
			return (ft_free_all(str, n));
		i = i + len;
		n++;
	}
	str[n] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**str;

	count = ft_count_word(s, c);
	str = malloc((count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = ft_fill_str(str, count, s, c);
	return (str);
}
