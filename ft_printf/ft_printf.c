/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:46:14 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/15 23:42:38 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "libft.h"

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
            if (*format == 'c')
                count += ft_putchar_fd(va_arg(args, int), 1);
            else if (*format == 's')
                count += ft_putstr_fd(va_arg(args, char *), 1);
            else if (*format == 'p')
            {
                count += ft_putstr_fd("0x", 1);
                count += ft_puthex_fd(va_arg(args, unsigned long), 1, 0);
            }
            else if (*format == 'd')
                count += ft_putnbr_fd(va_arg(args, int), 1);
            else if (*format == 'i')
                count += ft_putnbr_fd(va_arg(args, int), 1);
            else if (*format == 'u')
                count += ft_unsigned_putnbr_fd(va_arg(args, unsigned int), 1);
            else if (*format == 'x')
                count += ft_puthex_fd(va_arg(args, unsigned long), 1, 0);
            else if (*format == 'X')
            {
                count += ft_puthex_fd(va_arg(args, unsigned long), 1, 1);
            }
            else
                count += ft_putchar_fd('%', 1);
        }
        else
            count += ft_putchar_fd((*format), 1);
        format++;
    }
    va_end(args);
    return (count);
}

int main(void)
{
    int result_c =  ft_printf("%c\n", 'a');
    printf("%d\n", result_c);

    int result_s = ft_printf("%s\n", "Hello, World!");
    printf("%d\n", result_s);

    int result_p = ft_printf("%p\n", (void *)0x42);
    printf("%d\n", result_p);

    int result_d = ft_printf("%d\n", 42);
    printf("%d\n", result_d);

    int result_i = ft_printf("%i\n", 0x42);
    printf("%d\n", result_i);

    int result_u = ft_printf("%u\n", -1);
    printf("%d\n", result_u);

    int result_x = ft_printf("%x\n", 42);
    printf("%d\n", result_x);

    int result_X = ft_printf("%X\n", 42);
    printf("%d\n", result_X);
    
    int result_percent = ft_printf("%%\n");
    printf("%d\n", result_percent);

    return (0);
}
