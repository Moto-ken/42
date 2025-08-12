
#include "so_long.h"
#include "get_next_line/get_next_line.h"

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
	while (map[i])
	{
		if (i == 0 || i == last)
			result = start_end_line(map[i]);
		else 
			result =  bet_line(map[i]);
		if (result == 1)
			return (1);
		i++;
	}
	if (check_all(map))
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
		return (1);
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
	while (line[i])
	{
		if (line[i] == '\n')
		{
			i++;
			continue;
		}
		if (line[i] != '1')
			return (1);
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
		return (1);		
	while (line[i])
	{	
		if (line[i] == '\n')
		{
			i++;
			continue;
		}
		if (line[i] != 'C' && line[i] != 'E' && line[i] != 'P' && line[i] != '0' && line[i] != '1')
			return (1);
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
			return (1);
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