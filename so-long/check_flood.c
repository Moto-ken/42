/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:29:54 by kemotoha          #+#    #+#             */
/*   Updated: 2025/08/21 18:48:55 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y)
{
	if (!map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static char	**dup_map(char **map)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	while (j < i)
	{
		copy[j] = ft_strdup(map[j]);
		if (!copy[j])
		{
			free_map(copy);
			return (NULL);
		}
		j++;
	}
	copy[j] = NULL;
	return (copy);
}

static int	judge_tile(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] == 'C' || map_line[i] == 'E')
		{
			write(2, "error\nThe map is not connected.\n", 33);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_flood(char **map)
{
	t_game	game;
	char	**map_cpy;
	char	*map_line;

	game.map = map;
	find_player_position(&game);
	map_cpy = dup_map(map);
	if (!map_cpy)
		return (1);
	flood_fill(map_cpy, game.player_x, game.player_y);
	map_line = join_map_lines(map_cpy);
	if (!map_line)
	{
		free_map(map_cpy);
		return (1);
	}
	if (judge_tile(map_line))
	{
		free_map(map_cpy);
		free(map_line);
		return (1);
	}
	free_map(map_cpy);
	free(map_line);
	return (0);
}
