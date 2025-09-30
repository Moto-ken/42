
#include "pipex.h"

static int	open_files(char *infile_path, char *outfile_path, int *infile, int *outfile)
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
	*outfile = open(outfile_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*outfile < 0)
	{
		perror(outfile_path);
		close(*infile);
		return (1);
	}
	return (0);
}

static void	close_fds(int fd1, int fd2, int pipefd[2])
{
	close(fd1);
	close(fd2);
	close(pipefd[0]);
	close(pipefd[1]);
}

static int	return_status(pid_t pid1, pid_t pid2)
{
	int	status1;
	int	status2;

	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (1);
	if (open_files(argv[1], argv[4], &infile, &outfile))
		return (1);
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	if (run_children(infile, outfile, pipefd, argv, envp, &pid1, &pid2))
	{
		close_fds(infile, outfile, pipefd);
		return (1);
	}
	close_fds(infile, outfile, pipefd);
	return (return_status(pid1, pid2));
}

