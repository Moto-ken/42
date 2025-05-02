/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@studet.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 01:25:00 by kemotoha          #+#    #+#             */
/*   Updated: 2025/04/30 20:55:13 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

// int	main(void)
// {
// 	const char	s1[] = "hollo";
// 	const char	s2[] = "hollo";
// 	size_t		n;
// 	int			result;
// 	int			result2;

// 	n = 8;
// 	result = ft_strncmp(s1, s2, n);
// 	printf("ft_strncmp result: %d\n", result);
// 	result2 = strncmp(s1, s2, n);
// 	printf("strncmp result: %d\n", result2);
// 	return (0);
// }
