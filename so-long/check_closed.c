/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:03:43 by kemotoha          #+#    #+#             */
/*   Updated: 2025/08/26 01:57:54 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	bet_line(char *line)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	i = 0;
	if (line[len - 1] == '\n')
		len--;
	if (line[0] != '1' || line[len - 1] != '1')
	{
		write(2, "Error\nMap is not surrounded by walls\n", 38);
		return (1);
	}
	while (line[i])
	{
		if (line[i] != 'C' && line[i] != 'E' && line[i] != 'P' && line[i] != '0'
			&& line[i] != '1')
		{
			write(2, "Error\nInvalid character found in map\n", 38);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	start_end_line(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
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

int	check_closed(char **map)
{
	int	i;
	int	last;
	int	result;

	i = 0;
	while (map[i])
		i++;
	i--;
	last = i;
	i = 0;
	result = 0;
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
	return (0);
}
