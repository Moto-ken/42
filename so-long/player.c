/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:53:49 by kemotoha          #+#    #+#             */
/*   Updated: 2025/08/21 18:47:47 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_tile(t_game *game, char next_tile)
{
	if (next_tile == '1')
		return (0);
	if (next_tile == 'C')
		game->collected++;
	if (next_tile == 'E')
	{
		if (game->collected == game->total_collectibles)
			exit_game(game);
		else
			return (0);
	}
	return (1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	next_tile = game->map[new_y][new_x];
	if (!check_tile(game, next_tile))
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->steps++;
	ft_putnbr_fd(game->steps, 1);
	write(1, "\n", 1);
	draw_map(game);
}

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	count_collectibles(t_game *game)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	game->total_collectibles = count;
}
