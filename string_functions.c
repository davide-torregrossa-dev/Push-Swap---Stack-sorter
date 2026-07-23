/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:58:07 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/19 16:58:09 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_is_number(const char *str)
{
	int	i;

	if (str == NULL || str[0] == '\0')
		return (0);
	i = 0;
	if (char_to_number(str[0]) == -1)
	{
		if (str[0] != '-' && str[0] != '+')
			fail();
		i++;
	}
	while (str[i] != '\0')
	{
		if (char_to_number(str[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

int	string_equals(const char *s1, const char *s2)
{
	int	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*out;
	size_t	i;

	len = ft_strlen(s);
	out = malloc((len + 1) * sizeof(char));
	i = 0;
	if (out)
	{
		while (i < len)
		{
			out[i] = s[i];
			i++;
		}
	}
	out[i] = 0;
	return (out);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	i;
	size_t	amt_remaining_chars;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	amt_remaining_chars = s_len - start;
	if (len > amt_remaining_chars)
		len = amt_remaining_chars;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}