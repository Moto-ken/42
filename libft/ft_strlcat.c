/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@studet.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:26:58 by kemotoha          #+#    #+#             */
/*   Updated: 2025/04/30 20:51:00 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	max;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	max = size - dstlen - 1;
	if (size <= dstlen)
		return (size + srclen);
	while (i < max)
	{
		if (src[i] == '\0')
			break ;
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[i + dstlen] = '\0';
	return (srclen + dstlen);
}

// int	main(void)
// {
// 	char		dst[10] = "Hello, ";
// 	const char	*src = "world!";
// 	size_t		size;
// 	size_t		len;

// 	size = sizeof(dst);
// 	len = ft_strlcat(dst, src, size);
// 	printf("dst: %s\n", dst);
// 	printf("Returned length: %zu\n", len);
// 	return (0);
// }
