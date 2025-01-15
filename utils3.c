#include "pushswap.h"


static int	countwords(const char *s, char c)
{
	int	counter;
	int	inside;

	counter = 0;
	if (!s)
		return (0);
	while (*s)
	{
		inside = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			if (!inside)
			{
				counter++;
				inside = 1;
			}
			++s;
		}
	}
	return (counter);
}

static char	*words(const char *s, size_t len)
{
	size_t	i;
	char	*ret;

	if (!len || !s)
		return (NULL);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = *s;
		i++;
		s++;
	}
	ret[i] = '\0';
	return (ret);
}

static void	fireforce(char **s, size_t size)
{
	while (size > 0)
	{
		free(s[size - 1]);
		size--;
	}
	free(s);
}

static char	**split_of_split(const char *s, char c, char **ret, size_t len)
{
	size_t		k;
	const char	*start;

	k = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		start = s;
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			ret[k] = words(start, len);
			if (!ret[k])
				return (fireforce(ret, k), NULL);
			k++;
		}
	}
	return (ret);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		wordcount;
	size_t	len;

	if (!s)
		return (NULL);
	len = 0;
	wordcount = countwords(s, c);
	ret = malloc((wordcount + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[wordcount] = NULL;
	ret = split_of_split(s, c, ret, len);
	return (ret);
}