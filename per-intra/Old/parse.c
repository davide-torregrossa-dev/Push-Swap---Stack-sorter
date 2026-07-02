/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:23:45 by egarlasc          #+#    #+#             */
/*   Updated: 2026/06/30 19:50:38 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stringarray_find_index(char **arr, char **queries)
{
	int	i;
	int	q;

	if (arr == NULL || queries == NULL)
	{
		return (-1);
	}
	i = 0;
	while (arr[i] != NULL)
	{
		q = 0;
		while (queries[q] != NULL)
		{
			if (string_equals(arr[i], queries[q]))
				return (i);
			q++;
		}
		i++;
	}
	return (-1);
}

char	**get_args(char **av, int ac, int *is_alloc)
{
	int	i;

	i = flags_skipper(av, ac);
	if (ac - i == 0)
		return (NULL);
	if (ac - 1 == 1)
	{
		*is_alloc = 1;
		return (ft_split(av[i], ' '));
	}
	*is_alloc = 0;
	return (av + i);
}

int	flags_skipper(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (string_equals(av[i], "--simple")
			i++;
		else if (string_equals(av[i], "--medium")
			i++;
		else if (string_equals(av[i], "--complex")
			i++;
		else if (string_equals(av[i], "--adaptive")
			i++;
		else if (string_equals(av[i], "--bench")
			i++;
		else
			break ;
	}
	return (i);
}

int	is_valid_arg(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_limits_and_duplicates(char **args, int current_index, long num)
{
	int	i;

	if (num < -2147483648 || num > 2147483647)
		return (0);
	i = 0;
	while (i < current_index)
	{
		if (ft_atol(args[i]) == num)
			return (0);
		i++;
	}
	return (1);
}

int	validate_args(char **args)
{
	int	j;
	int	num;

	j = 0;
	while (args[j] != NULL)
	{
		if (is_valid_arg(args[j]) == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		num = ft_atol(args[j]);
		if (check_limits_and_duplicates(args, j, num) == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		j++;
	}
	return (1);
}
