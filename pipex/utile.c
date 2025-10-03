/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:03:32 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/03 17:05:29 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_paths(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*get_path_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*join_path(const char *dir, const char *cmd)
{
	char	*path;
	size_t	len_dir;
	size_t	len_cmd;
	int		need_slash;
	size_t	total_len;

	len_dir = ft_strlen(dir);
	len_cmd = ft_strlen(cmd);
	if (dir[len_dir - 1] != '/')
		need_slash = 1;
	else
		need_slash = 0;
	if (need_slash)
		total_len = len_dir + len_cmd + 2;
	else
		total_len = len_dir + len_cmd + 1;
	path = malloc(total_len);
	if (!path)
		return (NULL);
	ft_strlcpy(path, dir, total_len);
	if (need_slash)
		ft_strlcat(path, "/", total_len);
	ft_strlcat(path, cmd, total_len);
	return (path);
}
