/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:37:28 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/03 12:23:29 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    if (s == NULL)
        return ;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
}

// int main(void)
// {
//     int fd = 1;
//     char *str = "Hello, World\n";
    
//     ft_putstr_fd(str, fd);
//     return (0);
// }
