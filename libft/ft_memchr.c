/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@studet.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:00:34 by kemotoha          #+#    #+#             */
/*   Updated: 2025/04/30 20:53:54 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *)s;
	while (i < n)
	{
		if (s1[i] == (unsigned char)c)
			return ((void *)(s1 + i));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	s[] = "hello";
// 	int			c;
// 	size_t		n;
// 	char		*result;

// 	c = 'o';
// 	n = 5;
// 	result = ft_memchr(s, c, n);
// 	if (result == NULL)
// 		printf("Character not found\n");
// 	printf("%ld\n", result - s);
// 	return (0);
// }
