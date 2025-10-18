/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:31:20 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/16 05:01:32 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// delete ft_strncmp

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (unsigned char)s1[i] == (unsigned char)s2[i])
	{
		if (s1[i] == '\0')
			return (s1[i] - s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

bool	is_builtin(const char *cmd)
{
	if (!cmd)
		return (1);
	return (ft_strncmp(cmd, "echo", 4) == 0 || ft_strncmp(cmd, "cd", 2) == 0
		|| ft_strncmp(cmd, "pwd", 3) == 0 || ft_strncmp(cmd, "export", 6) == 0
		|| ft_strncmp(cmd, "unset", 5) == 0 || ft_strncmp(cmd, "env", 3) == 0
		|| ft_strncmp(cmd, "exit", 4) == 0);
}

int	main(int argc, char **argv, char **envp)
{
	char	**cmd_args;
	char	*cmd;

	(void)argc;
	cmd_args = &argv[1];
	cmd = cmd_args[0];
	if (is_builtin(cmd))
		run_builtin(cmd_args, envp);
	// else
	// 	gaibu_cmd_args(cmd_args);
	return (0);
}
