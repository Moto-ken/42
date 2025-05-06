/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 01:25:00 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/06 14:58:42 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (unsigned char)s1[i] == (unsigned char)s2[i])
	{
		if (s1[i] == '\0')
			return (s1[i] - s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {
// 	const char	s1[] = "abcdefgh";
// 	const char	s2[] = "abcdxyz";
// 	size_t		n;
// 	int			result;
// 	int			result2;

// 	n = 4;
// 	result = ft_strncmp(s1, s2, n);
// 	printf("ft_strncmp result: %d\n", result);
// 	result2 = strncmp(s1, s2, n);
// 	printf("strncmp result: %d\n", result2);
// 	return (0);
// }
