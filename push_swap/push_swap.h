/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:03:28 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/20 14:24:04 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

int					parse_arguments(int count, char **vale, t_node **stack_a);
void				push_node(t_node **stack_a, t_node *new_node);
t_node				*new_node(int value);

void				swap_stack(t_node **stack);
void				rotate_stack(t_node **stack);
void				reverse_rotate(t_node **stack);
void				sa(t_node **stack_a);
void				ra(t_node **stack_a);
void				rra(t_node **stack_a);
void				pb(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_a, t_node **stack_b);
void				rb(t_node **stack_b);
void				rrb(t_node **stack_b);

void				sort_2(t_node **stack_a);
void				sort_3(t_node **stack_a);
void				sort_4(t_node **stack_a, t_node **stack_b);
void				sort_5(t_node **stack_a, t_node **stack_b);
int					find_min(t_node *stack);
int					stack_size(t_node *stack);
int					find_pos(t_node *stack, int value);
void				move_to_top(t_node **stack, int value, char stack_name);
void				radix_sort(t_node **stack_a, t_node **stack_b, int size);

#endif
