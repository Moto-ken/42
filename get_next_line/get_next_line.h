/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:41:03 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/28 14:41:47 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
char    *save_remainder(char *str);
char    *extract_line(const char *str);
size_t  ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char    *ft_strdup(const char *s1);
void    free_remainder(char **remainder);

# endif