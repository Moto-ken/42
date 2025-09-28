
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
		printf("Trying: %s\n", full_path);
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
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	char **cmd_op = ft_split(cmd, ' ');
	if (!cmd_op)
	{
		perror("ft_split");
		close(infile);
		exit(EXIT_FAILURE);
	}
	char *path = parse_cmd(cmd_op[0], envp);
	if (!path)
	{
		perror("command not found");
		free_paths(cmd_op);
		exit(1);
	}
	execve(path, cmd_op, envp);
	perror("execve");
	free(path);
	free_paths(cmd_op);
	exit(1);
}

