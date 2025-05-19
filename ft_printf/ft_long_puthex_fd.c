/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_puthex_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:48:52 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/19 17:38:26 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_long_puthex_fd(unsigned long n, int fd)
{
	int			count;
	const char	*hex = "0123456789abcdef";
	int			i;
	char		buffer[16];

	count = 0;
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
