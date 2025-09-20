/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:03:02 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/20 14:12:59 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	swap_stack(stack_a);
	swap_stack(stack_b);
	write(1, "ss\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	write(1, "rr\n", 3);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
