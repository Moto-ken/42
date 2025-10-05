/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:03:10 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/05 01:39:09 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1_process(t_pipex *data)
{
	char	**cmd_op;

	if (dup2(data->infile, STDIN_FILENO) == -1)
		perror("dup2 infile");
	if (dup2(data->pipefd[1], STDOUT_FILENO) == -1)
		perror("dup2 pipefd[1]");
	close(data->infile);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	cmd_op = split_quotes(data->argv[2]);
	if (!cmd_op || !cmd_op[0])
	{
		ft_putendl_fd("pipex: invalid command", STDERR_FILENO);
		free_paths(cmd_op);
		exit(127);
	}
	validate_command(cmd_op, data->envp);
	exec_command(cmd_op, data->envp);
}

static void	child2_process(t_pipex *data)
{
	char	**cmd_op;
	char	*outfile_path;

	outfile_path = data->argv[4];
	data->outfile = open(outfile_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile < 0)
	{
		perror(outfile_path);
		exit(1);
	}
	if (dup2(data->pipefd[0], STDIN_FILENO) == -1)
		perror("dup2 pipefd[0]");
	if (dup2(data->outfile, STDOUT_FILENO) == -1)
		perror("dup2 outfile");
	close_fds(-1, data->outfile, data->pipefd);
	cmd_op = split_quotes(data->argv[3]);
	if (!cmd_op || !cmd_op[0])
	{
		ft_putendl_fd("pipex: invalid command", STDERR_FILENO);
		free_paths(cmd_op);
		exit(127);
	}
	validate_command(cmd_op, data->envp);
	exec_command(cmd_op, data->envp);
}

int	run_children(t_pipex *data)
{
	data->pid1 = fork();
	if (data->pid1 == -1)
	{
		perror("fork");
		return (1);
	}
	if (data->pid1 == 0)
		child1_process(data);
	data->pid2 = fork();
	if (data->pid2 == -1)
	{
		perror("fork");
		return (1);
	}
	if (data->pid2 == 0)
		child2_process(data);
	return (0);
}
