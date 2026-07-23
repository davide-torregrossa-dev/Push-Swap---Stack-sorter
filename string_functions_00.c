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

char	*ft_strdup(const char *s)
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
