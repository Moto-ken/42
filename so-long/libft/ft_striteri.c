/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@studet.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:17:02 by kemotoha          #+#    #+#             */
/*   Updated: 2025/05/06 13:14:34 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void apply_putchar(unsigned int i, char *c)
// {
//     (void)i;
//     ft_putchar_fd(*c, 1);
// }

// int main(void)
// {
//     char s[] = "Hello, World\n";
//     ft_striteri(s, apply_putchar);
//     return (0);
// }
