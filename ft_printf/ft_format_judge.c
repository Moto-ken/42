/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_judge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:37:49 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/20 00:22:11 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_char_ptr(char spec, va_list args);
static int	print_number(char spec, va_list args);

int	format_judge(char spec, va_list args)
{
	int	count;

	if (spec == 'c' || spec == 's' || spec == 'p')
		return (print_char_ptr(spec, args));
	else if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x'
		|| spec == 'X')
		return (print_number(spec, args));
	else if (spec == '%')
		return (ft_putchar_fd('%', 1));
	else
	{
		count = 0;
		count += ft_putchar_fd('%', 1);
		count += ft_putchar_fd(spec, 1);
		return (count);
	}
}

static int	print_char_ptr(char spec, va_list args)
{
	void	*ptr;
	char	*str;
	int		count;

	if (spec == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (spec == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			return (ft_putstr_fd("(null)", 1));
		return (ft_putstr_fd(str, 1));
	}
	if (spec == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
			return (ft_putstr_fd("(nil)", 1));
		count = ft_putstr_fd("0x", 1);
		return (count + ft_long_puthex_fd((unsigned long long)ptr, 1));
	}
	return (0);
}

static int	print_number(char spec, va_list args)
{
	unsigned long	val;

	if (spec == 'd' || spec == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (spec == 'u')
		return (ft_unsigned_putnbr_fd(va_arg(args, unsigned int), 1));
	if (spec == 'x' || spec == 'X')
	{
		val = va_arg(args, unsigned int);
		val &= 0xFFFFFFFFFFFFFFFF;
		return (ft_puthex_fd(val, 1, spec == 'X'));
	}
	return (0);
}
