/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:45:04 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/03 12:23:39 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

// int main(void)
// {
//     int fd = 1;
    
//     ft_putchar_fd('A', fd);
//     ft_putchar_fd('\n', fd);
//     return 0;
// }

// #include <fcntl.h>

// int main(void)
// {
//     int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return 1;
//     }
    
//     ft_putchar_fd('A', fd);
    
//     close(fd);
//     return 0;
// }