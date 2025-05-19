/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:31:28 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/19 16:35:37 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_puthex_fd(unsigned long n, int fd, int upper)
// {
// 	int		count;
// 	char	*hex;

// 	count = 0;
// 	if (upper == 0)
// 		hex = "0123456789abcdef";
// 	else
// 		hex = "0123456789ABCDEF";
// 	n = n & 0xFFFFFFFFFFFFFFFF;
// 	if (n >= 16)
// 		count += ft_puthex_fd(n / 16, fd, upper);
// 	count += ft_putchar_fd(hex[n % 16], fd);
// 	return (count);
// }

int	ft_puthex_fd(unsigned int n, int fd, int upper)
{
	int		count;
	char	*hex;
	int		i;
	char	buffer[16];

	count = 0;
	if (upper == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n == 0)
	{
		count += ft_putchar_fd('0', fd);
		return (count);
	}
	i = 0;
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n = n / 16;
	}
	while (--i >= 0)
		count += ft_putchar_fd(buffer[i], fd);
	return (count);
}

// int main(void)
// {
//     int fd = 1;
//     unsigned long num = 123456789;
//     int count = ft_puthex_fd(num, fd, 1);
//     printf("\nCount: %d\n", count);
//     return (0);
// }
