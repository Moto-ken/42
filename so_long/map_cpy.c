/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:29:54 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/03 14:23:16 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*replace_exit(const char *line)
{
	char	*dup;
	int		i;

	dup = ft_strdup(line);
	if (!dup)
		return (NULL);
	i = 0;
	while (dup[i])
	{
		if (dup[i] == 'E')
			dup[i] = '1';
		i++;
	}
	return (dup);
}

char	**copy_map_ignore_exit(char **map, int height)
{
	char	**copy;
	int		y;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < height)
	{
		copy[y] = replace_exit(map[y]);
		if (!copy[y])
		{
			while (--y >= 0)
				free(copy[y]);
			free(copy);
			return (NULL);
		}
		y++;
	}
	copy[height] = NULL;
	return (copy);
}

void	free_int_array(int **arr, int height)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < height)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	**alloc_int_array(int height, int width)
{
	int	**arr;
	int	i;

	arr = malloc(sizeof(int *) * height);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < height)
	{
		arr[i] = ft_calloc(width, sizeof(int));
		if (!arr[i])
		{
			free_int_array(arr, i);
			return (NULL);
		}
		i++;
	}
	return (arr);
}
