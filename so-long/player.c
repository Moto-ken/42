
#include "so_long.h"

void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->player_x + dx;
    int new_y = game->player_y + dy;
    char next_tile = game->map[new_y][new_x];
    if (next_tile == '1')
        return; // 壁だから進めない
    if (next_tile == 'C')
        game->collected++;
    if (next_tile == 'E') {
        if (game->collected == game->total_collectibles)
            exit_game(game); // 全部集めたのでクリア
        else
            return; // まだなので入れない
    }
    // 移動を反映
    game->map[game->player_y][game->player_x] = '0'; // 元の位置を床に
    game->map[new_y][new_x] = 'P'; // 新しい位置にプレイヤー

    game->player_x = new_x;
    game->player_y = new_y;
    game->steps++; // ステップ数カウント
    ft_putnbr_fd(game->steps, 1);
    write(1, "\n", 1);

    draw_map(game); // 画面を再描画
} //移動処理

void find_player_position(t_game *game)
{
    int y = 0;
    while (game->map[y])
    {
        int x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
}

void count_collectibles(t_game *game)
{
    int y = 0;
    int x;
    int count = 0;

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
    // game->collected = 0; // ここで? collected の初期化をする必要はある？
}
