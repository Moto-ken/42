
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
    mlx_expose_hook(game.win, render_window, &game);
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

int render_window(t_game *game)
{
	draw_map(game);
	return (0);
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

