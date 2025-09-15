/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:03:12 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/15 12:03:13 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	rotate_stack(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	rotate_stack(stack_b);
	write(1, "rb\n", 3);
}
