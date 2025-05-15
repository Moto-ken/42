/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:31:28 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/15 23:32:09 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex_fd(unsigned long n, int fd, int upper)
{
    int count;
    char *hex;

    count = 0;
    if (upper == 0)
        hex = "0123456789abcdef";
    else
        hex = "0123456789ABCDEF";
    if (n >= 16)
        count += ft_puthex_fd(n / 16, fd, upper);
    count += ft_putchar_fd(hex[n % 16], fd);
    return (count);
}

// int main(void)
// {
//     int fd = 1; 
//     unsigned long num = 123456789;
//     int count = ft_puthex_fd(num, fd, 1);
//     printf("\nCount: %d\n", count);
//     return 0;
// }
