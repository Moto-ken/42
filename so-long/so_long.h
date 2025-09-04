/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:55:25 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/03 14:07:39 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32

# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_ESC XK_Escape

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectible;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	**map;
	int		map_width;
	int		map_height;

	int		player_x;
	int		player_y;
	int		collected;
	int		total_collectibles;
	int		steps;

	int		**visited;
}			t_game;

typedef struct s_counts
{
	int		p;
	int		e;
	int		c;
}			t_counts;

char		**map(const char *filename);
int			count_lines(const char *filename);
void		free_map(char **map);
int			check_map(char **map);
char		*join_map_lines(char **map);
void		draw_map(t_game *game);
void		move_player(t_game *game, int dx, int dy);
int			key_hook(int keycode, t_game *game);
int			render_window(t_game *game);
void		destroy_images(t_game *game);
void		find_player_position(t_game *game);
void		count_collectibles(t_game *game);
int			exit_game(t_game *game);
// int			check_flood(char **map);
int			check_closed(char **map);
int			check_dfs(char **map);
void		free_int_array(int **arr, int height);
char		**copy_map_ignore_exit(char **map, int height);
int			**alloc_int_array(int height, int width);
#endif
