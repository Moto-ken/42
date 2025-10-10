/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:03:28 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/10 16:21:28 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	char	**argv;
	char	**envp;
	pid_t	pid1;
	pid_t	pid2;
}			t_pipex;

# define CMD_ERR_NOT_FOUND 1
# define CMD_ERR_NO_PERMISSION 2
# define CMD_ERR_NO_MEMORY 3

void		close_fds(int fd1, int fd2, int pipefd[2]);
char		*get_path_envp(char **envp);
int			is_valid_command(char *cmd, char **envp, int *cmd_error);
char		*join_path(const char *dir, const char *cmd);
void		free_paths(char **str);
char		*parse_cmd(char *cmd, char **envp);
void		validate_command(char **cmd_op, char **envp);
void		exec_command(char **cmd_op, char **envp);
int			run_children(t_pipex *data);
char		**split_quotes(const char *str);
int			count_tokens(const char *str);
int			ft_isspace(int c);
int			is_quote(char c);
int			token_len(const char *str);

#endif
