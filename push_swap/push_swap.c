/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:02:39 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/15 14:51:25 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	stack_size(t_node *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
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

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (parse_arguments(argc - 1, &argv[1], &stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!is_sorted(stack_a))
	{
		write(1, "OK\n", 3);
		return (0);
	}
	size = stack_size(stack_a);
	if (size == 2)
		sort_2(&stack_a);
	else if (size == 3)
		sort_3(&stack_a);
	else if (size == 4)
		sort_4(&stack_a, &stack_b);
	else if (size == 5)
		sort_5(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b, size);
	if (!is_sorted(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
