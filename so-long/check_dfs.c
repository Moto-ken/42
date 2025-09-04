/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:29:41 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/03 14:09:48 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return ;
	if (game->map[y][x] == '1' || game->visited[y][x])
		return ;
	game->visited[y][x] = 1;
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

static int	all_collectibles_reachable(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C' && !game->visited[y][x])
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	exit_reachable(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'E' && game->visited[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	all_collectibles_reachable_without_exit(t_game *game)
{
	char	**map_copy;
	int		**visited;
	int		reachable;
	t_game	temp;

	map_copy = copy_map_ignore_exit(game->map, game->map_height);
	if (!map_copy)
		return (0);
	visited = alloc_int_array(game->map_height, game->map_width);
	if (!visited)
	{
		free_map(map_copy);
		return (0);
	}
	temp = *game;
	temp.map = map_copy;
	temp.visited = visited;
	flood_fill(&temp, game->player_x, game->player_y);
	reachable = all_collectibles_reachable(&temp);
	free_map(map_copy);
	free_int_array(visited, game->map_height);
	return (reachable);
}

int	check_dfs(char **map)
{
	t_game	game;

	game.map = map;
	game.map_height = 0;
	while (map[game.map_height])
		game.map_height++;
	game.map_width = ft_strlen(map[0]);
	find_player_position(&game);
	game.visited = alloc_int_array(game.map_height, game.map_width);
	if (!game.visited)
		return (1);
	flood_fill(&game, game.player_x, game.player_y);
	if (exit_reachable(&game))
	{
		write(2, "error\nExit not reachable\n", 26);
		free_int_array(game.visited, game.map_height);
		return (1);
	}
	free_int_array(game.visited, game.map_height);
	if (all_collectibles_reachable_without_exit(&game))
	{
		write(2, "error\nCannot reach all collectibles before exit\n", 49);
		return (1);
	}
	return (0);
}
