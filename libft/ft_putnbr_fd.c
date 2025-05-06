/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:55:10 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/06 09:06:03 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
    {
        ft_putstr_fd("-2147483648", fd);
        return ;
    }
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = n * -1;
    }
    if (n >= 10)
        ft_putnbr_fd(n / 10, fd);
    ft_putchar_fd((n % 10) + '0', fd);
}

// int main(void)
// {
//     int fd = 1;
//     int n = -12345;
//     ft_putnbr_fd(n, fd);
//     write(fd, "\n", 1);
//     n = -2147483648;
//     ft_putnbr_fd(n, fd);
//     write(fd, "\n", 1);
//     return (0);
// }
