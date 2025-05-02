/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@studet.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:50:52 by kemotoha          #+#    #+#             */
/*   Updated: 2025/04/30 20:54:22 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (n > i)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	size_t n = 5;
// 	char s[] = "abcdefg";
// 	int c = 'x';
// 	memset(s, c, n);
// 	printf("%s", s);
// 	return (0);
// }