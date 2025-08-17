
#include "so_long.h"

int key_hook(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_game(game);
    else if (keycode == KEY_W)
        move_player(game, 0, -1);
    else if (keycode == KEY_S)
        move_player(game, 0, 1);
    else if (keycode == KEY_A)
        move_player(game, -1, 0);
    else if (keycode == KEY_D)
        move_player(game, 1, 0);
    return (0);
} //キー衆力の登録

int exit_game(t_game *game)
{
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    free_map(game->map);
    exit(0);
    return (0);
}