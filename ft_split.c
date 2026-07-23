#include "push_swap.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

static char	**clean_and_abort(char **out, size_t i)
{
	while (i > 0)
		free(out[--i]);
	free(out);
	return (0);
}

static int	string_count_words(char const *s, char c)
{
	size_t	i;
	int		cnt;

	if (!s)
		return (0);
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
			if (i == 0 || s[i - 1] == c)
				cnt++;
		i++;
	}
	return (cnt);
}

static char	*try_allocate_next_word(char const *s, size_t indexes[], char c)
{
	size_t	len;

	len = 0;
	while (s[indexes[1] + len] && s[indexes[1] + len] != c)
		len++;
	return (ft_substr(s, indexes[1], len));
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	indexes[2];

	if (!s)
		return (0);
	out = malloc((string_count_words(s, c) + 1) * sizeof(char *));
	if (!out)
		return (0);
	ft_bzero(indexes, sizeof(indexes));
	while (s[indexes[1]])
	{
		if (s[indexes[1]] == c)
			indexes[1]++;
		else
		{
			out[indexes[0]] = try_allocate_next_word(s, indexes, c);
			if (!out[indexes[0]])
				return (clean_and_abort(out, indexes[0]));
			indexes[1] += ft_strlen(out[indexes[0]]);
			indexes[0]++;
		}
	}
	out[indexes[0]] = 0;
	return (out);
}
