/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:03:14 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/03 23:41:15 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	validate_absolute_command(char *cmd, int *cmd_error)
{
	if (access(cmd, X_OK) == 0)
		return (1);
	if (access(cmd, F_OK) != 0)
		*cmd_error = CMD_ERR_NOT_FOUND;
	else
		*cmd_error = CMD_ERR_NO_PERMISSION;
	return (0);
}

static char	**get_split_paths(char **envp, int *cmd_error)
{
	char	*path_str;
	char	**paths;

	path_str = get_path_envp(envp);
	if (!path_str)
	{
		*cmd_error = CMD_ERR_NOT_FOUND;
		return (NULL);
	}
	paths = ft_split(path_str, ':');
	if (!paths)
		*cmd_error = CMD_ERR_NO_MEMORY;
	return (paths);
}

static int	validate_path_command(char *cmd, char **envp, int *cmd_error)
{
	int		i;
	char	**paths;
	char	*full_path;

	paths = get_split_paths(envp, cmd_error);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (access(full_path, X_OK) == 0)
		{
			free_paths(paths);
			free(full_path);
			return (1);
		}
		free(full_path);
		i++;
	}
	free_paths(paths);
	*cmd_error = CMD_ERR_NOT_FOUND;
	return (0);
}

int	is_valid_command(char *cmd, char **envp, int *cmd_error)
{
	if (!cmd || cmd[0] == '\0')
	{
		*cmd_error = CMD_ERR_NOT_FOUND;
		return (0);
	}
	if (ft_strchr(cmd, '/'))
		return (validate_absolute_command(cmd, cmd_error));
	else
		return (validate_path_command(cmd, envp, cmd_error));
}
