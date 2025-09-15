
#include "push_swap.h"

int find_min(t_node *stack)
{
	int min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int find_pos(t_node *stack, int value)
{
	int i = 0;
	while (stack)
	{
		if (stack->value == value)
			return i;
		stack = stack->next;
		i++;
	}
	return -1; // 見つからなかった場合（基本起こらない）
}

void move_to_top(t_node **stack, int value, char stack_name)
{
	int pos = find_pos(*stack, value);
	int size = stack_size(*stack);

	if (pos <= size / 2)
	{
		while ((*stack)->value != value)
			(stack_name == 'a') ? ra(stack) : rb(stack);
	}
	else
	{
		while ((*stack)->value != value)
			(stack_name == 'a') ? rra(stack) : rrb(stack);
	}
}

