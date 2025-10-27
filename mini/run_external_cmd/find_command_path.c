/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:49:57 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/28 02:18:24 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

static char *join_path(char *dir, char *cmd)
{
	char *path;
	size_t len;

	len = ft_strlen(dir) + ft_strlen(cmd) + 2;  // +2 for '/' and '\0'
	path = malloc(len);
	if (!path)
		return (NULL);
	
	ft_strlcpy(path, dir, len);
	ft_strlcat(path, "/", len);
	ft_strlcat(path, cmd, len);
	return (path);
}

char *get_env_value(t_env *env_list, const char *key)
{
	t_env *var;

	var = find_env(env_list, key);
	if (var)
		return (var->value);
	return (NULL);
}

static void free_split(char **split)
{
	int i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char *find_command_path(t_shell *shell, char *cmd)
{
	char *path_env;
	char **paths;
	char *full_path;
	int i;

	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/') ||
		(cmd[0] == '.' && cmd[1] == '.' && cmd[2] == '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		
		return (NULL);
	}
	path_env = get_env_value(shell->env_list, "PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (full_path && access(full_path, X_OK) == 0)
		{
			free_split(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_split(paths);
	return (NULL);
}
