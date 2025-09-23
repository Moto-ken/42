/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:02:10 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/23 19:03:28 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_number(const char *str, int *i, int sign, int *out)
{
	long	nb;

	nb = 0;
	if (str[*i] < '0' || str[*i] > '9')
		return (1);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb = nb * 10 + (str[*i] - '0');
		if ((sign == 1 && nb > INT_MAX) || (sign == -1 && (-nb) < INT_MIN))
			return (1);
		(*i)++;
	}
	*out = (int)(nb * sign);
	return (0);
}

int	new_ft_atoi(const char *nptr, int *out)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (parse_number(nptr, &i, sign, out))
		return (1);
	if (nptr[i] != '\0')
		return (1);
	return (0);
}
