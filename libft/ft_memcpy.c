/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@studet.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 07:53:27 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/02 14:35:56 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*q;

	if (dest == NULL || src == NULL)
		return (NULL);
	i = 0;
	p = (unsigned char *)dest;
	q = (const unsigned char *)src;
	while (i < n)
	{
		p[i] = q[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char		dest[20];
// 	const char	src[] = "hello";
// 	size_t		n;

// 	n = 3;
// 	ft_memcpy(dest, src, n);
// 	dest[n] = '\0';
// 	printf("%s", (char *)dest);
// 	return (0);
// }
