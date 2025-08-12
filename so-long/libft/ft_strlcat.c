/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:26:58 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/09 20:02:18 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	i = 0;
	while (src[i] && dstlen + i + 1 < size)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

// #include <bsd/string.h>

// int	main(void)
// {
// 	// 1. dstがNULLの場合
// 	char *src1 = "nyan !";
// 	size_t result1 = strlcat(((void *)0), src1, 2);
// 	printf("Test 1 (dst == NULL): %zu\n", result1);
// 	size_t result_ft1 = ft_strlcat(((void *)0), src1, 2);
// 	printf("ft_strlcat Test 1 (dst == NULL): %zu\n", result_ft1);

// 	// 2. srcがNULLの場合
// 	char dst2[20] = "Hello ";
// 	size_t result2 = strlcat(dst2, ((void *)0), 20);
// 	printf("Test 2 (src == NULL): %zu\n", result2);
// 	size_t result_ft2 = ft_strlcat(dst2, ((void *)0), 20);
// 	printf("ft_strlcat Test 2 (src == NULL): %zu\n", result_ft2);

// 	// 3. 両方がNULLの場合（srcとdst）
// 	size_t result3 = strlcat(((void *)0), ((void *)0), 2);
// 	printf("Test 3 (dst == NULL, src == NULL): %zu\n", result3);
// 	size_t result_ft3 = ft_strlcat(((void *)0), ((void *)0), 2);
// 	printf("ft_strlcat Test 3 (dst == NULL, src == NULL): %zu\n",
// 	result_ft3);

// 	return (0);
// }