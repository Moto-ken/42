/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:46:14 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/20 01:24:03 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (format == NULL)
		return (0);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (!*++format)
				return (va_end(args), -1);
			count += format_judge(*format, args);
		}
		else
			count += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
