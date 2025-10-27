
#include "../builtin.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	l;

	i = 0;
	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	if (start >= l)
		return (ft_strdup(""));
	if (len > l - start)
		len = l - start;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	free_split(char **words, size_t j)
{
	while (j > 0)
	{
		j--;
		free(words[j]);
	}
	free(words);
}

size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**split_words(const char *s, char c, char **words)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		words[j] = ft_substr(s, start, i - start);
		if (words[j] == NULL)
		{
			free_split(words, j);
			return (NULL);
		}
		j++;
	}
	words[j] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (s == NULL)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (words == NULL)
		return (NULL);
	return (split_words(s, c, words));
}
