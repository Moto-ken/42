
#include "push_swap.h"

void push_stack(t_node **dest, t_node **src)
{
	t_node *tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void pa(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_b)
		return;
	push_stack(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void pb(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a)
		return;
	push_stack(stack_b, stack_a);
	write(1, "pb\n", 3);
}
