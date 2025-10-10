/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:03:24 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/10 16:30:12 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_infiles(char *infile_path, int *infile)
{
	*infile = open(infile_path, O_RDONLY);
	if (*infile < 0)
	{
		perror(infile_path);
		*infile = open("/dev/null", O_RDONLY);
		if (*infile < 0)
		{
			perror("/dev/null");
			return (1);
		}
	}
	return (0);
}

void	close_fds(int fd1, int fd2, int pipefd[2])
{
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
	if (pipefd[0] != -1)
		close(pipefd[0]);
	if (pipefd[1] != -1)
		close(pipefd[1]);
}

static int	return_status(pid_t pid1, pid_t pid2)
{
	int	status1;
	int	status2;

	if (waitpid(pid1, &status1, 0) == -1)
		perror("waitpid");
	if (waitpid(pid2, &status2, 0) == -1)
		perror("waitpid pid2");
	return (WEXITSTATUS(status2));
	return (127);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
		return (1);
	data.argv = argv;
	data.envp = envp;
	data.outfile = -1;
	if (open_infiles(argv[1], &data.infile))
		return (1);
	if (pipe(data.pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	if (run_children(&data))
	{
		close_fds(data.infile, data.outfile, data.pipefd);
		return (1);
	}
	close_fds(data.infile, data.outfile, data.pipefd);
	return (return_status(data.pid1, data.pid2));
}
