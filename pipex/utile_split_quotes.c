
#include "pipex.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

int ft_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\v' || c == '\f' || c == '\r');
}

int	token_len(const char *str)
{
	int		i = 0;
	char	quote;

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
		while (str[i] && !ft_isspace((unsigned char)str[i]) && !is_quote(str[i]))
			i++;
	}
	return (i);
}

int	count_tokens(const char *str)
{
	int	count = 0;
	int		len;

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
