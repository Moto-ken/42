
#include "push_swap.h"

void ss(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	if (!*stack_b || !(*stack_b)->next)
		return;
	swap_stack(stack_a);
	swap_stack(stack_b);
	write(1, "ss\n", 3);
}

void rr(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	if (!*stack_b || !(*stack_b)->next)
		return;
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	write(1, "rr\n", 3);
}

void rrr(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	if (!*stack_b || !(*stack_b)->next)
		return;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
