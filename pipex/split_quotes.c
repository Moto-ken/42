/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemotoha <kemotoha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:20:20 by kemotoha          #+#    #+#             */
/*   Updated: 2025/10/10 16:21:03 by kemotoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*extract_plain_token(const char *str, int len)
{
	char	*token;
	int		i;

	i = 0;
	token = malloc(len + 1);
	if (!token)
		return (NULL);
	while (i < len)
	{
		token[i] = str[i];
		i++;
	}
	token[i] = '\0';
	return (token);
}

static char	*extract_token(const char *str, int len)
{
	char	*token;
	int		i;
	int		j;

	if (is_quote(str[0]))
	{
		i = 1;
		j = 0;
		token = malloc(len - 1);
		if (!token)
			return (NULL);
		while (i < len - 1)
			token[j++] = str[i++];
		token[j] = '\0';
		return (token);
	}
	else
		return (extract_plain_token(str, len));
}

static char	**process_token(const char *str, char **tokens, int *i, int *tok_i)
{
	int	len;
	int	j;

	len = token_len(&str[*i]);
	tokens[*tok_i] = extract_token(&str[*i], len);
	if (!tokens[*tok_i])
	{
		j = 0;
		while (j < *tok_i)
		{
			free(tokens[j]);
			j++;
		}
		free(tokens);
		return (NULL);
	}
	(*tok_i)++;
	(*i) += len;
	return (tokens);
}

char	**split_quotes(const char *str)
{
	int		i;
	int		tok_i;
	int		tok_count;
	char	**tokens;

	i = 0;
	tok_i = 0;
	tok_count = count_tokens(str);
	tokens = malloc(sizeof(char *) * (tok_count + 1));
	if (!tokens)
		return (NULL);
	while (str[i])
	{
		while (str[i] && ft_isspace((unsigned char)str[i]))
			i++;
		if (str[i])
		{
			tokens = process_token(str, tokens, &i, &tok_i);
			if (!tokens)
				return (NULL);
		}
	}
	tokens[tok_i] = NULL;
	return (tokens);
}
