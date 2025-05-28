/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:48:38 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/28 15:24:50 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

// int	main(void)
// {
// 	int	fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	line = "";
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// 	return (0);
// }

int main(void)
{
    char *line;

    printf("Enter text:\n");
    while ((line = get_next_line(0)) != NULL)
    {
        if (line[0] == '\0') 
        {
            free(line);
            break;
        }
        printf("You entered: %s", line);
        free(line);
    }
    {
        printf("You entered: %s", line);
        free(line);
    }
    return 0;
}
