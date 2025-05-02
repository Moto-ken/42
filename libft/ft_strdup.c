/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@studet.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:59:20 by kemotoha          #+#    #+#             */
/*   Updated: 2025/04/30 22:17:34 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}

// int	main(void)
// {
// 	const char	s[] = "hello";
// 	char		*copy;

// 	copy = ft_strdup(s);
// 	if (copy)
// 	{
// 		printf("%s\n", copy);
// 		free(copy);
// 	}
// 	return (0);
// }
