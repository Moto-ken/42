/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:59:07 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/28 14:55:53 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *remainder = NULL;
	char buffer[BUFFER_SIZE + 1];
	char *line;
	ssize_t bytes_read;
	char *tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!remainder || !ft_strchr(remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free_remainder(&remainder);
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(remainder, buffer);
		if (!tmp)
		{
			free_remainder(&remainder);
			return (NULL);
		}
		free_remainder(&remainder);
		remainder = tmp;
	}
	if (!remainder || remainder[0] == '\0')
	{
		free_remainder(&remainder);
		return (NULL);
	}
	line = extract_line(remainder);
	if (!line)
	{
		free_remainder(&remainder);
		return (NULL);
	}
	tmp = save_remainder(remainder);
	free_remainder(&remainder);
	remainder = tmp;
	if (remainder && remainder[0] == '\0')
		free_remainder(&remainder);
	return (line);
}

