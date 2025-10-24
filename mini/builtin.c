/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:31:20 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/22 16:05:44 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	is_builtin(const char *cmd)
{
	if (!cmd)
		return (1);
	return (ft_strncmp(cmd, "echo", 4) == 0 || ft_strncmp(cmd, "cd", 2) == 0
		|| ft_strncmp(cmd, "pwd", 3) == 0 || ft_strncmp(cmd, "export", 6) == 0
		|| ft_strncmp(cmd, "unset", 5) == 0 || ft_strncmp(cmd, "env", 3) == 0
		|| ft_strncmp(cmd, "exit", 4) == 0);
}

static void init_env_from_envp(t_shell *shell, char **envp)
{
    int i = 0;
    
    while (envp[i])
    {
        char *key = extract_key(envp[i]);
        char *value = extract_value(envp[i]);
        set_variable(shell, key, value, 1);
        free(key);
        free(value);
        i++;
    }
}

static void free_env_list(t_env *env_list)
{
    t_env *current;
    t_env *next;

    current = env_list;
    while (current)
    {
        next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
}

int main(int argc, char **argv, char **envp)
{
    t_shell shell;
    char **cmd_args;
    char *cmd;

    shell.env_list = NULL;
    shell.pwd = get_pwd();
    if (!shell.pwd)
        return (1);

    init_env_from_envp(&shell, envp); 
    (void)argc;
    cmd_args = &argv[1];
    cmd = cmd_args[0];
    
    if (is_builtin(cmd))
        run_builtin(&shell, cmd_args);
    // else
    //     run_external_cmd(&shell, cmd_args);
    free_env_list(shell.env_list);
    free(shell.pwd);
    return (0);
}