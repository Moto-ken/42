/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_external_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:00:12 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/28 02:17:39 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

static void free_envp(char **envp)
{
	int i;

	if (!envp)
		return;
	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

static char *create_env_string(const char *key, const char *value)
{
	char *str;
	size_t len;

	len = ft_strlen(key) + ft_strlen(value) + 2;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, key, len);
	ft_strlcat(str, "=", len);
	ft_strlcat(str, value, len);
	return (str);
}

static char **generate_envp(t_env *env_list)
{
	t_env *current;
	char **envp;
	int count;
	int i;

	current = env_list;
	count = count_exported_vars(env_list);
	envp = malloc(sizeof(char *) * (count + 1));
	if (!envp)
		return (NULL);
	i = 0;
	while (current)
	{
		if (current->exported)
		{
			envp[i] = create_env_string(current->key, current->value);
			if (!envp[i])
			{
				free_envp(envp);
				return (NULL);
			}
			i++;
		}
		current = current->next;
	}
	envp[i] = NULL;
	return (envp);
}

void run_external_cmd(t_shell *shell, char **cmd_args)
{
	pid_t	pid;
	char	*cmd_path;
	char	**envp;
	int		status;
	int		has_slash;
	char	*path_env;

	if (!cmd_args || !cmd_args[0])
		return ;
	cmd_path = find_command_path(shell, cmd_args[0]);
	has_slash = (ft_strchr(cmd_args[0], '/') != NULL);
	path_env = get_env_value(shell->env_list, "PATH");
	if (!cmd_path)
	{
		write(2, "bash: ", 6);
		write(2, cmd_args[0], ft_strlen(cmd_args[0]));
		if (has_slash || !path_env)
			write(2, ": No such file or directory\n", 28);
		else
			write(2, ": command not found\n", 20);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return ;
	}
	if (pid == 0)
	{
		envp = generate_envp(shell->env_list);
		if (!envp)
			exit(1);
		execve(cmd_path, cmd_args, envp);
		perror("execve");
		free(cmd_path);
		free_envp(envp);
		exit(127);
	}
	free(cmd_path);
	waitpid(pid, &status, 0);
}
