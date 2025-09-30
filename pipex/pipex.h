
#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "libft.h"

char    *get_path_envp(char **envp);
int     is_valid_command(char *cmd, char **envp);
char    *join_path(const char *dir, const char *cmd);
void    free_paths(char **str);
// void	child1_process(int infile, int pipefd[2], char *cmd, char **envp);
// void	child2_process(int outfile, int pipefd[2], char *cmd, char **envp);
char    *parse_cmd(char *cmd, char **envp);
void	validate_command(char **cmd_op, char **envp);
void	exec_command(char **cmd_op, char **envp);
int     run_children(int infile, int outfile, int pipefd[2], char **argv, char **envp, pid_t *pid1, pid_t *pid2);

#endif
