
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (check_argumrnts(argc, argv, envp))
		return (1);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
	{
		perror("open");
		return (1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid1 == 0)
		child1_process(infile, pipefd, argv[2], envp);
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid2 == 0)
		child2_process(outfile, pipefd, argv[3], envp);
	close(infile);
	close(outfile);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

