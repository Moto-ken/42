/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@studet.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 06:42:55 by kemotoha          #+#    #+#             */
/*   Updated: 2025/04/30 20:52:36 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

// int	main(void)
// {
// 	const char *test_cases[] = {"42", "-42", "   42", "+42", "123abc", "abc123",
// 		"2147483647", "-2147483648", "2147483648", "-2147483649", NULL};
// 	for (int i = 0; test_cases[i] != NULL; i++)
// 	{
// 		const char *str = test_cases[i];
// 		int ft_result = ft_atoi(str);
// 		int atoi_result = atoi(str);
// 		printf("Input: \"%s\"\n", str);
// 		printf("ft_atoi result: %d\n", ft_result);
// 		printf("atoi result:    %d\n\n", atoi_result);
// 	}

// 	return (0);
// }