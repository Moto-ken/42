
#include "pipex.h"

static void	child1_process(int infile, int pipefd[2], char *cmd, char **envp)
{
	char	**cmd_op;

	if (dup2(infile, STDIN_FILENO) == -1)
		perror("dup2 infile");
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		perror("dup2 pipefd[1]");
	close(pipefd[0]);
	close(pipefd[1]);
	cmd_op = ft_split(cmd, ' ');
	if (!cmd_op || !cmd_op[0])
	{
		ft_putendl_fd("pipex: invalid command", STDERR_FILENO);
		free_paths(cmd_op);
		exit(127);
	}
	validate_command(cmd_op, envp);
	exec_command(cmd_op, envp);
}

static void	child2_process(int outfile, int pipefd[2], char *cmd, char **envp)
{
	char	**cmd_op;

	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		perror("dup2 pipefd[0]");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		perror("dup2 outfile");
	close(pipefd[0]);
	close(pipefd[1]);
	cmd_op = ft_split(cmd, ' ');
	if (!cmd_op || !cmd_op[0])
	{
		ft_putendl_fd("pipex: invalid command", STDERR_FILENO);
		free_paths(cmd_op);
		exit(127);
	}
	validate_command(cmd_op, envp);
	exec_command(cmd_op, envp);
}

int	run_children(int infile, int outfile, int pipefd[2], char **argv, char **envp, pid_t *pid1, pid_t *pid2)
{
	*pid1 = fork();
	if (*pid1 == -1)
	{
		perror("fork");
		return (1);
	}
	if (*pid1 == 0)
		child1_process(infile, pipefd, argv[2], envp);

	*pid2 = fork();
	if (*pid2 == -1)
	{
		perror("fork");
		return (1);
	}
	if (*pid2 == 0)
		child2_process(outfile, pipefd, argv[3], envp);
	return (0);
}
