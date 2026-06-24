/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:33:55 by egarlasc          #+#    #+#             */
/*   Updated: 2026/06/24 14:41:01 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	flags_skipper(int ac, char **av)
{
	int	i;

	i = 1;
	while(i < ac)
	{
		if (ft_strncmp(av[i], "--simple", 9) == 0)
			i++;
		else if (ft_strncmp(av[i], "--medium", 9) == 0)
			i++;
		else if (ft_strncmp(av[i], "--complex", 10) == 0)
			i++;
		else if (ft_strncmp(av[i], "--adaptive", 11) == 0)
			i++;
		else if (ft_strncmp(av[i], "--bench", 8) == 0)
			i++;
		else
			break;
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
	while(str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**args;
	int		i;
	int		is_alloc;

	is_alloc = 0;
	i = flags_skipper(ac, av);
	if (ac - i == 0)
		return (1);
	if (ac - i == 1)
	{
		args = ft_split(av[i], ' ');
		is_alloc = 1;
	}
	else
	{
		args = av + 1;
		is_alloc = 0;
	}
}
