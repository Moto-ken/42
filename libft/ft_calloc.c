/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:05:33 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/09 16:40:54 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return ((void *)malloc(0));
	if (nmemb > ((size_t)-1) / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// int	main(void)
// {
// 	size_t	max_size;
// 	size_t	a;
// 	size_t	b;
// 	void	*overflow;

// 	max_size = (size_t)-1;
// 	printf("%p\n", ft_calloc(10, 4));
// 	a = max_size / 2 + 1;
// 	b = 3;
// 	overflow = ft_calloc(a, b);
// 	printf("%p\n", overflow);
// 	return (0);
// }
