/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:54:10 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/06 17:30:47 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	result = malloc(ft_strlen(s) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char	str_toupper(unsigned int i, char c)
// {
// 	(void)i;
// 	return ((char)ft_toupper((int)c));
// }

// int	main(void)
// {
// 	const char	*s = "hello world";
// 	char		*new_str;

// 	new_str = ft_strmapi(s, str_toupper);
// 	if (new_str)
// 	{
// 		printf("%s\n", new_str);
// 		free(new_str);
// 	}
// 	return (0);
// }
