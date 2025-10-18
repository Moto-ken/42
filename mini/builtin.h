/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:05:22 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/16 04:12:30 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// delete ft_strncmp

void	run_builtin(char **cmd, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	echo_cmd(char **cmd);
void	env_cmd(char **cmd);
void	exit_cmd(char **cmd);
