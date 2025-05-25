/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:59:07 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/25 09:54:44 by kemotoha         ###   ########.fr       */
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

	if (fd == -1)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(remainder);
			remainder = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(remainder, buffer);
		free(remainder);
		if (!tmp)
			return (NULL);
		remainder = tmp;
		if (ft_strchr(remainder, '\n'))
			break ;
		if (bytes_read == 0)
			break ;
	}
	if (!remainder || remainder[0] == '\0')
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	line = extract_line(remainder);
	remainder = save_remainder(remainder);
	return (line);
}
