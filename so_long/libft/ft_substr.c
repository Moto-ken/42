/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:55:50 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/09 18:09:48 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	l;

	i = 0;
	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	if (start >= l)
		return (ft_strdup(""));
	if (len > l - start)
		len = l - start;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	const char s[] = "Hello, world";
// 	char *result;
// 	result = ft_substr(s, 3, 5);
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }