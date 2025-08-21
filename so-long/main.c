/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:53:02 by kemotoha          #+#    #+#             */
/*   Updated: 2025/08/21 19:27:00 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collected = 0;
	game->total_collectibles = 0;
	game->steps = 0;
}

static int	setup_game(t_game *game, const char *map_file)
{
	int	line_count;

	init_game(game);
	line_count = count_lines(map_file);
	if (line_count <= 0)
		return (1);
	game->map = map(map_file);
	if (!game->map)
		return (1);
	if (check_map(game->map))
	{
		free_map(game->map);
		return (1);
	}
	game->map_height = line_count;
	game->map_width = ft_strlen(game->map[0]);
	find_player_position(game);
	count_collectibles(game);
	return (0);
}

static int	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall_32x32.xpm",
			&w, &h);
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor_32x32.xpm", &w, &h);
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			"textures/player_32x32.xpm", &w, &h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit_32x32.xpm",
			&w, &h);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/chest_32x32.xpm", &w, &h);
	if (!game->img.wall || !game->img.floor || !game->img.player
		|| !game->img.exit || !game->img.collectible)
		return (1);
	return (0);
}

static int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game->map);
		return (1);
	}
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		free_map(game->map);
		return (1);
	}
	if (load_images(game))
	{
		free_map(game->map);
		mlx_destroy_window(game->mlx, game->win);
		return (1);
	}
	return (0);
}

int	main(void)
{
	t_game	game;

	if (setup_game(&game, "maps/map.ber"))
		return (1);
	if (init_window(&game))
		return (1);
	draw_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_expose_hook(game.win, render_window, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	return (0);
}
