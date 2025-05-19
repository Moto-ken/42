/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:55:21 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/16 17:41:09 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_unsigned_putnbr_fd(n / 10, fd);
	count += ft_putchar_fd((n % 10) + '0', fd);
	return (count);
}

// int main(void)
// {
//     int fd = 1;
//     unsigned int num = -1;
//     int count = ft_unsigned_putnbr_fd(num, fd);
//     printf("\nCount: %d\n", count);
//     return (0);
// }
