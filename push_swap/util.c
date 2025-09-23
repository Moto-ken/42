/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:03:35 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/23 18:52:09 by kemotoha         ###   ########.fr       */
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

void	move_to_top(t_node **stack, int value)
{
	int	pos;
	int	size;

	pos = find_pos(*stack, value);
	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while ((*stack)->value != value)
			ra(stack);
	}
	else
	{
		while ((*stack)->value != value)
			rra(stack);
	}
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_split(char **split, int count)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
}
