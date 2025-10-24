/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:38:24 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/22 15:32:16 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

void pwd_cmd(t_shell *shell, int fd)
{
    char *cwd;
    (void)shell;
    // 常にgetcwd()で現在のディレクトリを取得
    cwd = get_pwd();
    if (!cwd)
    {
        write(2, "pwd: error retrieving current directory: ", 41);
        perror("getcwd");
        return;
    }
    ft_putstr_fd(cwd, fd);
    ft_putchar_fd('\n', fd);
    free(cwd);
}
