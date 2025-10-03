/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:03:17 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/03 23:37:56 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*search_cmd(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	int		i;

	path_env = get_path_envp(envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (access(full_path, X_OK) == 0)
		{
			free_paths(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

char	*parse_cmd(char *cmd, char **envp)
{
	if (!cmd || cmd[0] == '\0')
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	return (search_cmd(cmd, envp));
}

void	validate_command(char **cmd_op, char **envp)
{
	int	cmd_error;

	if (is_valid_command(cmd_op[0], envp, &cmd_error))
		return ;
	if (ft_strchr(cmd_op[0], '/') && cmd_error == CMD_ERR_NOT_FOUND)
		perror(cmd_op[0]);
	else if (cmd_error == CMD_ERR_NO_PERMISSION)
		perror(cmd_op[0]);
	else if (cmd_error == CMD_ERR_NO_MEMORY)
		perror(cmd_op[0]);
	else
	{
		write(2, cmd_op[0], ft_strlen(cmd_op[0]));
		write(2, ": command not found\n", 20);
	}
	free_paths(cmd_op);
	write(STDOUT_FILENO, "", 0);
	if (cmd_error == CMD_ERR_NOT_FOUND)
		exit(127);
	else
		exit(126);
}

void	exec_command(char **cmd_op, char **envp)
{
	char	*path;

	path = parse_cmd(cmd_op[0], envp);
	if (!path)
	{
		perror("parse_cmd");
		free_paths(cmd_op);
		write(STDOUT_FILENO, "", 0);
		exit(127);
	}
	execve(path, cmd_op, envp);
	perror("execve");
	free(path);
	free_paths(cmd_op);
	exit(1);
}
