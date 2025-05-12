/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:46:14 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/12 21:18:39 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_printf(const char *format, ...)
{
    va_list	args;
    int		count;

    count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'd')
                count += ft_putnbr_fd(va_arg(args, int), 1);
            else if (*format == 's')
                count += ft_putstr_fd(va_arg(args, char *), 1);
            else if (*format == 'c')
                count += ft_putchar_fd(va_arg(args, int), 1);
            else
                count += ft_putchar_fd('%', 1);
        }
        else
            count += ft_putchar_fd(*format), 1;
        format++;
    }
    va_end(args);
    return (count);
}

int main(void)
{
    ft_printf("hello %s, %d, %c\n", "world", 42, '!');
    return (0);
}