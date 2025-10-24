/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:38:17 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/22 22:29:09 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

void env_cmd(t_shell *shell, char **cmd)
{
    t_env *current;
    
    if (cmd[1] != NULL)
    {
        write(2, "env: '", 6);
        write(2, cmd[1], ft_strlen(cmd[1]));
        write(2, "': No such file or directory\n", 30);
        exit(127);
    }
    current = shell->env_list;
    while (current)
    {
        if (current->exported)
        {
            ft_putstr_fd(current->key, 1);
            ft_putchar_fd('=', 1);
            ft_putstr_fd(current->value, 1);
            ft_putchar_fd('\n', 1);
        }
        current = current->next;
    }
}