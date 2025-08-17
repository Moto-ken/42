
#include "so_long.h"

int	check_map(char **map)
{
	int	i = 0;
	int last;
	int result = 0;

	if (check_square(map))
		return (1);
	while (map[i])
		i++;
	last = i - 1;
	i = 0;
	while (map[i])
	{
		if (i == 0 || i == last)
			result = start_end_line(map[i]);
		else 
			result = bet_line(map[i]);
		if (result == 1)
			return (1);
		i++;
	}
	if (check_all(map))
		return (1);
	if (check_flood(map))
		return (1);
	return (result);
}

int check_all(char **map)
{
	char *str = join_map_lines(map);
	int i = 0;
	int count_p = 0;
	int count_e = 0;
	int count_c = 0;
	if (!map)
		return (1);
	while (str[i])
	{
		if (str[i] == 'P')
			count_p++;
		else if (str[i] == 'E')
			count_e++;
		else if (str[i] == 'C')
			count_c++;
		i++;
	}
	free(str);
	if (count_p != 1 || count_e != 1 || count_c < 1)
	{
		write(2, "Error\nMap must contain one P, one E, and at least one C\n", 57);
		return (1);
	}
	return (0);
}

char *join_map_lines(char **map)
{
	char *result = NULL;
	char *tmp;
	int i = 0;
	if (!map || !map[0])
		return (NULL);
	result = ft_strdup("");
	if (!result)
		return (NULL);
	while (map[i])
	{
		tmp = ft_strjoin(result, map[i]);
		free(result);
		if (!tmp)
			return (NULL);
		result = tmp;
		i++;
	}
	return (result);
}

int start_end_line(char *line)
{
	int i = 0;
	int len = ft_strlen(line);

	if (len > 0 && line[len - 1] == '\n')
		len--;
	if (len == 0)
		return (1);
	while (i < len)
	{
		if (line[i] != '1')
		{
			write(2, "Error\nTop or bottom line is not closed by walls\n", 49);
			return (1);
		}
		i++;
	}
	return (0);
}

int bet_line(char *line)
{
	int len = ft_strlen(line);
	int i = 0;
	if (line[len - 1] == '\n')
		len--;
	if (line[0] != '1' || line[len - 1] != '1')
	{
		write(2, "Error\nMap is not surrounded by walls\n", 38);
		return (1);
	}
	while (line[i])
	{	
		if (line[i] == '\n')
		{
			i++;
			continue;
		}
		if (line[i] != 'C' && line[i] != 'E' && line[i] != 'P' && line[i] != '0' && line[i] != '1')
		{
			write(2, "Error\nInvalid character found in map\n", 38);
			return (1);
		}
		i++;
	}
	return (0);
}

int check_square(char **map)
{
	int i = 1;
	size_t len = ft_strlen(map[0]);

	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			write(2, "error\nMap is not rectangular\n", 30);
			return (1);
		}
		i++;
	}
	return (0);
}

char *remove_newline(char *line)
{
	size_t len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

void flood_fill(char **map, int x, int y)
{
	if (!map[y] || !map[y][x])
		return;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int check_flood(char **map)
{
	t_game game;
	game.map = map;
	find_player_position(&game);
	char **map_cpy = dup_map(map);
	if (!map_cpy)
		return (1);
	flood_fill(map_cpy, game.player_x, game.player_y);
	char *map_line = join_map_lines(map_cpy);
	if (!map_line)
	{
		free_map(map_cpy);
		return (1);
	}
	int i = 0;
	while (map_line[i])
	{
		if (map_line[i] == 'C' || map_line[i] == 'E')
		{
			write(2, "error\nThe map is not connected.\n", 33);
			free_map(map_cpy);
			free (map_line);
			return (1);
		}
		i++;
	}
	free_map(map_cpy);
	free(map_line);
	return (0);
}

char **dup_map(char **map)
{
	char **copy;
	int i = 0;
	int j = 0;

	while (map[i])
		i++;
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);

	while (j < i)
	{
		copy[j] = ft_strdup(map[j]);
		if (!copy[j])
		{
			free_map (copy);
			return (NULL);
		}
		j++;
	}
	copy[j] = NULL;
	return  (copy);
}
