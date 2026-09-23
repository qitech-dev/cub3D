/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qijin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:23:43 by qijin             #+#    #+#             */
/*   Updated: 2025/11/26 18:23:46 by qijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_len_fd(char c, int fd);
int		ft_putstr_len_fd(char *s, int fd);
int		ft_putendl_len_fd(char *s, int fd);
int		ft_putnbr_len_fd(int n, int fd);
int		ft_putnbr_base_len(unsigned int n, char *base, int fd);
int		ft_putnbr_u_len(unsigned int n, int fd);
int		ft_putptr_len(void *ptr);
size_t	ft_strlen(const char *str);

#endif