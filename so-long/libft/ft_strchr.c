/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:48:08 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/09 16:02:53 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

// int	main(void)
// {
// 	const char s[] = "hello";
// 	int c = 0;
// 	char *result = ft_strchr(s, c);
// 	printf("%s\n", result);
// 	printf("%ld\n", result - s);
// 	return (0);
// }