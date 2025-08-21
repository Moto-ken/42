/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:53:42 by kemotoha          #+#    #+#             */
/*   Updated: 2025/08/21 19:00:50 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(const char *filename)
{
	int		fd;
	int		line_count;
	char	*line;

	line_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n' && line[0] != '\0')
			line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

static char	*remove_newline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

static char	**read_map_lines(int fd, int line_count)
{
	char	**result;
	char	*line;
	int		i;

	result = malloc(sizeof(char *) * (line_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line && i < line_count)
	{
		result[i++] = remove_newline(line);
		line = get_next_line(fd);
	}
	result[i] = NULL;
	if (i != line_count)
	{
		free_map(result);
		return (NULL);
	}
	return (result);
}

char	**map(const char *filename)
{
	int		fd;
	int		line_count;
	char	**result;

	line_count = count_lines(filename);
	if (line_count <= 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	result = read_map_lines(fd, line_count);
	close(fd);
	return (result);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
