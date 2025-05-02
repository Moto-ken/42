/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@studet.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:12:17 by kemotoha          #+#    #+#             */
/*   Updated: 2025/04/30 21:58:14 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char s[] = "hello";
// 	size_t n = 10;
// 	size_t i = 0;

// 	ft_bzero(s, n);
// 	while (i < n)
// 	{
// 		printf("s[%zu] = 0x%02x\n", i, (unsigned char)s[i]);
// 		i++;
// 	}
// 	return (0);
// }