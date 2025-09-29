
#include "pipex.h"

char *parse_cmd(char *cmd, char **envp)
{
	if (!cmd || cmd[0] == '\0')
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
    }
	char *path_env = get_path_envp(envp);
	if (!path_env)
		return (NULL);
	char **paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	int i = 0;
	while (paths[i] != NULL)
	{
		char *full_path = join_path(paths[i], cmd);
		if (access(full_path, X_OK) == 0)
		{
			free_paths(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

void	child1_process(int infile, int pipefd[2], char *cmd, char **envp)
{
	char	**cmd_op;
	char	*path;

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
		write (STDOUT_FILENO, "", 0);
		if (errno == ENOENT)
			exit(127);
		else 
			exit(126);
	}
	path = parse_cmd(cmd_op[0], envp);
	if (!path)
	{
		perror("parse_cmd");
		free_paths(cmd_op);
		write(STDOUT_FILENO, "", 0);
		exit(127);
	}
	execve(path, cmd_op, envp);
	perror("execve");
	free(path);
	free_paths(cmd_op);
	exit(1);
}

