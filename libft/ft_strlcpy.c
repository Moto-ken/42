/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@studet.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:10:02 by kemotoha          #+#    #+#             */
/*   Updated: 2025/04/30 20:54:43 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		while (src[i])
			i++;
	}
	return (i);
}

// int	main(void)
// {
// 	const char	src[] = "abcdefghijkl";
// 	char		dest[8];
// 	size_t		size;

// 	size = 10;
// 	ft_strlcpy(dest, src, size);
// 	printf("%zu\n", ft_strlcpy(dest, src, size));
// 	printf("%s\n", dest);
// 	return (0);
// }
