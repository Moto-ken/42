/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:31:19 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/21 04:23:47 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_3(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (b < a && a < c)
		sa(stack_a);
	else if (b < c && c < a)
		ra(stack_a);
	else if (c < a && a < b)
		rra(stack_a);
	else if (c < b && b < a)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_4(t_node **stack_a, t_node **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	move_to_top(stack_a, min);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	i;

	i = 0;
	while (i < 2)
	{
		min = find_min(*stack_a);
		move_to_top(stack_a, min);
		pb(stack_a, stack_b);
		i++;
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
