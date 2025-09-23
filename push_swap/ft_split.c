/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:16:14 by kemotoha          #+#    #+#             */
/*   Updated: 2025/09/23 18:52:19 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
			count++;
		while (str[i] && !ft_isspace(str[i]))
			i++;
	}
	return (count);
}

static char	*split_dup(char *str, int start, int end)
{
	int		len;
	char	*result;
	int		i;

	len = end - start + 1;
	result = malloc(len);
	if (!result)
		return (NULL);
	i = 0;
	while (start < end)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

static char	*extract_word(char *str, int *i)
{
	int		start;
	char	*word;

	while (str[*i] && ft_isspace(str[*i]))
		(*i)++;
	start = *i;
	if (!str[*i])
		return (NULL);
	while (str[*i] && !ft_isspace(str[*i]))
		(*i)++;
	word = split_dup(str, start, *i);
	return (word);
}

char	**ft_split(char *str)
{
	int		count;
	char	**result;
	int		i;
	int		j;

	count = count_words(str);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j < count)
	{
		result[j] = extract_word(str, &i);
		if (!result[j])
		{
			while (--j >= 0)
				free(result[j]);
			free(result);
			return (NULL);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}
