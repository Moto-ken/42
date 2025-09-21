/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:03:20 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/22 03:47:08 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

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

static int	new_ft_atoi(const char *nptr, int *out)
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

static int	duplicate(t_node *stack, int nb)
{
	while (stack)
	{
		if (stack->value == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	parse_arguments(int count, char **vale, t_node **stack_a)
{
	int		i;
	int		nb;
	t_node	*new;

	i = count - 1;
	nb = 0;
	new = NULL;
	while (i >= 0)
	{
		if (is_valid_number(vale[i]))
		{
			free_stack(stack_a);
			return (1);
		}
		if (new_ft_atoi(vale[i], &nb))
		{
			free_stack(stack_a);
			return (1);
		}
		if (duplicate(*stack_a, nb))
		{
			free_stack(stack_a);
			return (1);
		}
		new = new_node(nb);
		if (!new)
			return (1);
		push_node(stack_a, new);
		i--;
	}
	return (0);
}
