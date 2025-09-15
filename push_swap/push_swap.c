
#include "push_swap.h"

int is_sorted(t_node *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int stack_size(t_node *stack_a)
{
	int i ;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

void sort_2(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void sort_3(t_node **stack_a)
{
	int a = (*stack_a)->value;
	int b = (*stack_a)->next->value;
	int c = (*stack_a)->next->next->value;

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

void sort_5(t_node **stack_a, t_node **stack_b)
{
	int min;
	
	// 1. 最小を見つけて B に移動（2回繰り返す）
	for (int i = 0; i < 2; i++)
	{
		min = find_min(*stack_a);
		move_to_top(stack_a, min, 'a'); // ra/rra で最小を先頭に
		pb(stack_a, stack_b);           // 先頭をBへ
	}

	// 2. 残り3つを sort_3
	sort_3(stack_a);

	// 3. Bから戻す
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);

	// 4. 必要なら調整（Bの順序が逆な場合など）
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}


int main(int argc, char *argv[])
{
	t_node *stack_a = NULL;
	t_node *stack_b = NULL;

	if (argc < 2)
		return (0);
	if (parse_arguments(argc - 1, &argv[1], &stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}

	if (!is_sorted(stack_a))
		return (0);

	// 3. 要素数で分岐
	int size = stack_size(stack_a);
	if (size == 2)
		sort_2(&stack_a);
	else if (size == 3)
		sort_3(&stack_a);
	else if (size <= 5)
		sort_5(&stack_a, &stack_b);
	// else
	// 	radix_sort(&stack_a, &stack_b);
	while (stack_a) // check stack_a.
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	// // 4. メモリ解放
	// free_stack(&stack_a);
	// free_stack(&stack_b);

	return (0);
}
