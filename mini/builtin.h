/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:05:22 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/22 22:21:24 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	int				exported;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	t_env	*env_list;
	char	*pwd;
}	t_shell;

char	*get_pwd(void);
int		count_token(char **tokens);
int		is_valid_varname(const char *var);
char	*extract_key(const char *str);
char	*extract_value(const char *str);

void	set_variable(t_shell *shell, char *key, char *value, int exported);
t_env	*find_env(t_env *env_list, const char *key);

void	run_builtin(t_shell *shell, char **cmd);
void	echo_cmd(char **cmd);
void	cd_cmd(char **cmd, t_shell *shell, int fd);
void	pwd_cmd(t_shell *shell, int fd);
void	export_cmd(t_shell *shell, char **cmd, int fd);
void	unset_cmd(t_shell *shell, char **cmd);
void	env_cmd(t_shell *shell, char **cmd);
void	exit_cmd(char **cmd);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);

#endif
