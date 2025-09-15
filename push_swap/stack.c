
#include "push_swap.h"

t_node *new_node(int value)
{
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void push_node(t_node **stack_a, t_node *new_node)
{
	new_node->next = *stack_a;
	*stack_a = new_node;
}
