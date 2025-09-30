
#include "pipex.h"

static int validate_absolute_command(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (1);
	if (access(cmd, F_OK) != 0)
		errno = ENOENT;
	else
		errno = EACCES;
	return (0);
}

static char **get_split_paths(char **envp)
{
	char *path_str = get_path_envp(envp);
	if (!path_str)
	{
		errno = ENOENT;
		return (NULL);
	}
	char **paths = ft_split(path_str, ':');
	if (!paths)
		errno = ENOMEM;
	return paths;
}


static int validate_path_command(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;

	paths = get_split_paths(envp);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
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

int is_valid_command(char *cmd, char **envp)
{
	if (!cmd || cmd[0] == '\0')
	{
		errno = ENOENT;
		return (0);
	}
	if (ft_strchr(cmd, '/'))
		return (validate_absolute_command(cmd));
	else
		return (validate_path_command(cmd, envp));
}
