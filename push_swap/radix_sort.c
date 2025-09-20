/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:33:31 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/20 14:27:22 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quicksort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_index(t_node **stack, int size)
{
	int		*arr;
	t_node	*tmp;
	int		i;
	int		j;

	arr = malloc(sizeof(int) * size);
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	quicksort(arr, size);
	tmp = *stack;
	while (tmp)
	{
		j = 0;
		while (j < size && arr[j] != tmp->value)
			j++;
		tmp->index = j;
		tmp = tmp->next;
	}
	free(arr);
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	max_bits = 0;
	assign_index(stack_a, size);
	while ((size - 1) >> max_bits)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
