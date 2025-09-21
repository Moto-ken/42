
#include "push_swap.h"

void	free_split(char **split, int count)
{
	int	i;

	if (!split)
		return;
	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
}


static int ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int count_words(char *str)
{
	int i = 0;
	int count = 0;
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

static char *split_dup(char *str, int start, int end)
{
	int len = end - start + 1;
	char *result = malloc(len);
	if (!result)
		return(NULL);
	int i = 0;
	while (start < end)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

char **ft_split(char *str)
{
	int count = count_words(str);
	char **result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	int i = 0;
	int j = 0;
	int start = 0;
	while (str[i] && j < count)
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		start = i;
		if (!str[i])
			break;
		while (str[i] && !ft_isspace(str[i]))
			i++;
		result[j] = split_dup(str, start, i);
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
