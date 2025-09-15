/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:03:35 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/15 14:40:54 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_pos(t_node *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	move_to_top(t_node **stack, int value, char stack_name)
{
	int	pos;
	int	size;

	pos = find_pos(*stack, value);
	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while ((*stack)->value != value)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while ((*stack)->value != value)
		{
			if (stack_name == 'b')
				rra(stack);
			else
				rrb(stack);
		}
	}
}
