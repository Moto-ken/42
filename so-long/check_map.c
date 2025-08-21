/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:53:26 by kemotoha          #+#    #+#             */
/*   Updated: 2025/08/21 18:49:52 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_counts	count_map_elements(const char *str)
{
	t_counts	counts;
	int			i;

	counts.p = 0;
	counts.e = 0;
	counts.c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			counts.p++;
		else if (str[i] == 'E')
			counts.e++;
		else if (str[i] == 'C')
			counts.c++;
		i++;
	}
	return (counts);
}

char	*join_map_lines(char **map)
{
	char	*result;
	char	*tmp;
	int		i;

	result = NULL;
	i = 0;
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

static int	check_all(char **map)
{
	char		*str;
	t_counts	counts;

	if (!map)
		return (1);
	str = join_map_lines(map);
	if (!str)
	{
		free(str);
		return (1);
	}
	counts = count_map_elements(str);
	free(str);
	if (counts.p != 1 || counts.e != 1 || counts.c < 1)
	{
		write(2, "Error\nMap must contain one P, one E, and at least one C\n",
			57);
		return (1);
	}
	return (0);
}

static int	check_square(char **map)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(map[0]);
	if (len == 0)
		return (1);
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

int	check_map(char **map)
{
	if (check_square(map))
		return (1);
	if (check_closed(map))
		return (1);
	if (check_all(map))
		return (1);
	if (check_flood(map))
		return (1);
	return (0);
}
