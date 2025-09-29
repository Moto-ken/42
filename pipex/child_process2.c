
#include "pipex.h"
void	child2_process(int outfile, int pipefd[2], char *cmd, char **envp)
{
	char	*cmd_path;
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
	if (!is_valid_command(cmd_op[0], envp))
	{
		if (ft_strchr(cmd_op[0], '/') && errno == ENOENT)
			perror(cmd_op[0]);
		else if (errno == EACCES)
			perror(cmd_op[0]);
		else if (errno == ENOMEM)
			perror(cmd_op[0]);
		else
		{
			write(2, cmd_op[0], ft_strlen(cmd_op[0]));
			write(2, ": command not found\n", 20);
		}
		free_paths(cmd_op);
		if (errno == ENOENT)
			exit(127);
		else 
			exit(126);
	}
	cmd_path = parse_cmd(cmd_op[0], envp);
	if (!cmd_path)
	{
		perror("parse_cmd");
		free_paths(cmd_op);
		exit(127);
	}
	execve(cmd_path, cmd_op, envp);
	perror("execve");
	free(cmd_path);
	free_paths(cmd_op);
	exit(1);
}
