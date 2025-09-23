/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:03:20 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/23 19:03:06 by kemotoha         ###   ########.fr       */
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

static int	validate_number(char *str, t_node **stack_a, int *nb)
{
	if (is_valid_number(str))
	{
		free_stack(stack_a);
		return (1);
	}
	if (new_ft_atoi(str, nb))
	{
		free_stack(stack_a);
		return (1);
	}
	if (duplicate(*stack_a, *nb))
	{
		free_stack(stack_a);
		return (1);
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
		if (validate_number(vale[i], stack_a, &nb))
			return (1);
		new = new_node(nb);
		if (!new)
			return (1);
		push_node(stack_a, new);
		i--;
	}
	return (0);
}
