
#include "pipex.h"

void	child2_process(int outfile, int pipefd[2], char *cmd, char **envp)
{
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	char *cmd_path;
	char **cmd_op = ft_split(cmd, ' ');
	if (!cmd_op)
	{
		perror("ft_split");
		close(outfile);
		exit(EXIT_FAILURE);
	}
	cmd_path = parse_cmd(cmd_op[0], envp);
	if (!cmd_path)
	{
		perror("command not found");
		free_paths(cmd_op);
		exit(EXIT_FAILURE);
	}
	execve(cmd_path, cmd_op, envp);
	perror("execve");
	free(cmd_path);
	free_paths(cmd_op);
	exit(EXIT_FAILURE);
}

