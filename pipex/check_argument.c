
#include "pipex.h"

int is_valid_command(char *cmd, char **envp)
{
	int i;

	i = 0;
	if (!cmd || cmd[0] == '\0')
	{
		errno = ENOENT;
		return (0);
	}
	if (ft_strchr(cmd, '/'))  
	{
		if (access(cmd, X_OK) == 0)
			return (1);
		else
		{
			if (access(cmd, F_OK) != 0)
				errno = ENOENT;
			else
				errno = EACCES;
			return (0);
		}
	}
	char *path_str = get_path_envp(envp);
	if (!path_str)
	{
		errno = ENOENT;
		return (0);
	}
	char **paths = ft_split(path_str, ':');
	if (!paths)
	{
		errno = ENOMEM;
		return (0);
	}
	while (paths[i] != NULL)
	{
		char *full_path = join_path(paths[i], cmd);
		if (access(full_path, X_OK) == 0)
		{
			free_paths(paths);
			free(full_path);
			return (1);
		}
		free(full_path);
		i++;
	}
	free_paths(paths);
	errno = ENOENT;
	return (0);
}

int check_arguments(int argc, char **argv)
{
	if (argc != 5)
		return (1);
	if (access(argv[1], R_OK) != 0)
	{
		perror("Error");
		return (1);
	}
	int fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Output file error");
		return (1);
	}
	close(fd);
	return (0);
}
