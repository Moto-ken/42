/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:59:57 by kemotoha          #+#    #+#             */
/*   Updated: 2025/08/21 18:51:20 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*get_tile_image(char tile, t_game *game)
{
	if (tile == '1')
		return (game->img.wall);
	if (tile == '0')
		return (game->img.floor);
	if (tile == 'P')
		return (game->img.player);
	if (tile == 'E')
		return (game->img.exit);
	if (tile == 'C')
		return (game->img.collectible);
	return (NULL);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			img = get_tile_image(game->map[y][x], game);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, x
					* TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

int	render_window(t_game *game)
{
	draw_map(game);
	return (0);
}
