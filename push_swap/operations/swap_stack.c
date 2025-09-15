/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:03:15 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/15 12:03:17 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	swap_stack(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	swap_stack(stack_b);
	write(1, "sb\n", 3);
}
