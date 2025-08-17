
#include "so_long.h"

int	count_lines(const char *filename)
{
	int		fd;
	int		lines = 0;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		if (line[0] != '\n' && line[0] != '\0')
			lines++;
		free(line);
	}
	close(fd);
	return (lines);
}

char **map(const char *filename)
{
	int		fd;
	int		line_count = count_lines(filename);
	char	**result;
	int		i = 0;
	char	*line;

	if (line_count <= 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);

	result = malloc(sizeof(char *) * (line_count + 1));
	if (!result)
		return (NULL);

	while ((line = get_next_line(fd)) && i < line_count)
		result[i++] = remove_newline(line);
	result[i] = NULL;
	if (i != line_count)
	{
		free_map(result);
		return (NULL);
	}
	close(fd);
	return (result);
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
