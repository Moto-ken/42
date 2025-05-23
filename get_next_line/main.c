/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:48:38 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/23 10:57:47 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
    close(fd);
    return (0);
}

// int main(void)
// {
//     char *line;

//     printf("Enter text (Ctrl+D to end):\n");
//     while ((line = get_next_line(0)) != NULL) // fd = 0 は標準入力
//     {
//         printf("You entered: %s", line); // lineの中に\nが含まれている前提
//         free(line);
//     }
//     return 0;
// }
