
#include "so_long.h"
#include "get_next_line/get_next_line.h"

int	main(void)
{
	t_game 	game;
	int		line_count;
    init_game(&game);
	// 1. マップの行数を数える
	line_count = count_lines("map.ber");
	if (line_count <= 0)
		return (1);
	// 2. マップ読み込み
	game.map = map("map.ber");
	if (!game.map)
		return (1);
	// 3. マップが正しいか確認
	if (check_map(game.map))
	{
		printf("error\n");
		free_map(game.map);
		return (1);
	}
	// 4. マップサイズ取得
	game.map_height = line_count;
	game.map_width = ft_strlen(game.map[0]);
	// 5. mlx初期化とウィンドウ作成

	find_player_position(&game);
	count_collectibles(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(
		game.mlx,
		game.map_width * TILE_SIZE,
		game.map_height * TILE_SIZE,
		"so_long"
	);
	// 6. 画像読み込み & マップ描画
	load_images(&game);
	draw_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
    mlx_hook(game.win, 17, 0, exit_game, &game);
	// 7. イベントループ
	mlx_loop(game.mlx);
	// 8. メモリ解放（ループ終わったら）
	free_map(game.map);
	return (0);
}

void load_images(t_game *game)
{
    int w;
	int h;

    game->img.wall = mlx_xpm_file_to_image(game->mlx, "xpm/wall_32x32.xpm", &w, &h);
    game->img.floor = mlx_xpm_file_to_image(game->mlx, "xpm/floor_32x32.xpm", &w, &h);
    game->img.player = mlx_xpm_file_to_image(game->mlx, "xpm/player_32x32.xpm", &w, &h);
    game->img.exit = mlx_xpm_file_to_image(game->mlx, "xpm/exit_32x32.xpm", &w, &h);
    game->img.collectible = mlx_xpm_file_to_image(game->mlx, "xpm/chest_32x32.xpm", &w, &h);
}

void draw_map(t_game *game)
{
    int x;
    int y = 0;
    void *img;

    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            char tile = game->map[y][x];
            img = NULL;
            if (tile == '1')
                img = game->img.wall;
            else if (tile == '0')
                img = game->img.floor;
            else if (tile == 'P')
                img = game->img.player;
            else if (tile == 'E')
                img = game->img.exit;
            else if (tile == 'C')
                img = game->img.collectible;
            if (img)
                mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

void	free_map(char **map)
{
	if (!map)
		return;
	int i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

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
    printf("Move: %d\n", game->steps);

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

int exit_game(t_game *game)
{
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    free_map(game->map);
    exit(0);
    return (0);
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
    game->collected = 0; // ここで collected の初期化も必ずやる
}

void init_game(t_game *game)
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

