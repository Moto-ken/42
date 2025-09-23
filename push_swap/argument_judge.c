/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_judge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:24:16 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/23 17:34:59 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

int	argc2_parse(char *arg, t_node **stack_a)
{
	char	**split_args;
	int		split_argc;
	int		res;

	if (!ft_strchr(arg, ' '))
		return (parse_arguments(1, &arg, stack_a));
	split_args = ft_split(arg);
	if (!split_args || !*split_args)
		return (1);
	split_argc = 0;
	while (split_args[split_argc])
		split_argc++;
	res = parse_arguments(split_argc, split_args, stack_a);
	free_split(split_args, split_argc);
	return (res);
}

int	argument_judge(int argc, char **argv, t_node **stack_a)
{
	if (argc == 2)
	{
		if (argc2_parse(argv[1], stack_a))
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	else
	{
		if (parse_arguments(argc - 1, &argv[1], stack_a))
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}
