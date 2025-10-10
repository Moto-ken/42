/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_split_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:20:37 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/10 16:20:38 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	token_len(const char *str)
{
	int		i;
	char	quote;

	i = 0;
	if (is_quote(str[i]))
	{
		quote = str[i++];
		while (str[i] && str[i] != quote)
			i++;
		if (str[i] == quote)
			i++;
	}
	else
	{
		while (str[i] && !ft_isspace((unsigned char)str[i])
			&& !is_quote(str[i]))
			i++;
	}
	return (i);
}

int	count_tokens(const char *str)
{
	int	count;
	int	len;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace((unsigned char)*str))
			str++;
		if (*str)
		{
			len = token_len(str);
			count++;
			str += len;
		}
	}
	return (count);
}
