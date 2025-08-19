
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
}

int exit_game(t_game *game)
{
    destroy_images(game);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    free_map(game->map);
    exit(0);
    return (0);
}

void destroy_images(t_game *game)
{
    if (game->img.wall)
        mlx_destroy_image(game->mlx, game->img.wall);
    if (game->img.floor)
        mlx_destroy_image(game->mlx, game->img.floor);
    if (game->img.player)
        mlx_destroy_image(game->mlx, game->img.player);
    if (game->img.exit)
        mlx_destroy_image(game->mlx, game->img.exit);
    if (game->img.collectible)
        mlx_destroy_image(game->mlx, game->img.collectible);
}
