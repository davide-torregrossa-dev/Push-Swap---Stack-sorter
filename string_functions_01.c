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

int	string_has_space(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (char_is_space(s[i]))
			return (1);
		i++;
	}
	return (0);
}
