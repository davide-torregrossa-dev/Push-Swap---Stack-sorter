/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:11:10 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/06 14:48:57 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fail(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

char	**flagnames_array_create(void)
{
	char	**flags;

	flags = (char **)malloc(4 * sizeof(char *));
	if (flags == NULL)
		return (NULL);
	flags[STRATEGIES_ADAPTIVE_CLI] = "--adaptive";
	flags[STRATEGIES_SIMPLE] = "--simple";
	flags[STRATEGIES_MEDIUM] = "--medium";
	flags[STRATEGIES_COMPLEX] = "--complex";
	return (flags);
}

int	input_get_strategy(char **av, int bench_flag_found)
{
	char	**flagnames;
	int		flag_index;
	int		arg_index;

	arg_index = 1 + bench_flag_found;
	flagnames = flagnames_array_create();
	flag_index = array_find_string(flagnames, 4, av[arg_index]);
	if (flag_index == -1)
	{
		if (!string_is_number(av[arg_index]))
		{
			free(flagnames);
			fail();
		}
		flag_index = STRATEGIES_ADAPTIVE;
	}
	free(flagnames);
	return (flag_index);
}
