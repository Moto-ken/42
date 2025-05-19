/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:54:35 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/19 22:38:08 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_puthex_fd(unsigned int n, int fd, int upper);
int	ft_unsigned_putnbr_fd(unsigned int n, int fd);
int	ft_long_puthex_fd(unsigned long n, int fd);
int	format_judge(char spec, va_list args);

#endif