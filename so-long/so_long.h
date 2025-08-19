
#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include "libft/libft.h"

#define TILE_SIZE 32

#define KEY_W XK_w
#define KEY_A XK_a
#define KEY_S XK_s
#define KEY_D XK_d
#define KEY_ESC XK_Escape

typedef struct s_img {
    void *wall;
    void *floor;
    void *player;
    void *exit;
    void *collectible;
} t_img;

typedef struct s_game {
    void *mlx;
    void *win;
    t_img img;
    char **map;
    int map_width;
    int map_height;

    int     player_x;
    int     player_y;
    int     collected;
    int     total_collectibles;
    int     steps;
} t_game;

char **map(const char *filename);
int	count_lines(const char *filename);
void	free_map(char **map);
int	check_map(char **map);
int start_end_line(char *line);
int bet_line(char *line);
int check_all(char **map);
char *join_map_lines(char **map);
int load_images(t_game *game);
void draw_map(t_game *game);
int check_square(char **map);
char *remove_newline(char *line);
void move_player(t_game *game, int dx, int dy);
int key_hook(int keycode, t_game *game);
int render_window(t_game *game);
void destroy_images(t_game *game);
void find_player_position(t_game *game);
void count_collectibles(t_game *game);
int  exit_game(t_game *game);
void init_game(t_game *game);
char **dup_map(char **map);
int check_flood(char **map);
void flood_fill(char **map, int x, int y);

#endif
