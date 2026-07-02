/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:11:10 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/02 15:19:46 by dtorregr         ###   ########.fr       */
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
//	if (flag_index == STRATEGIES_ADAPTIVE)
//		flag_index = STRATEGIES_ADAPTIVE_CLI;
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

void	input_handling(char **av, int ac, t_program *programpt,
		t_stack *stack_apt)
{
	int	ints_start_from;

	if (ac == 1)
		exit(1);
	programpt->benchmode = string_equals(av[1], "--bench");
	programpt->strategy = STRATEGIES_ADAPTIVE;
	programpt->strategy = input_get_strategy(av, programpt->benchmode);
	ints_start_from = 1 + programpt->benchmode
		+ (programpt->strategy != STRATEGIES_ADAPTIVE);
	printf("benchmode: %d\nstrategy: %d\nhas_strategy_flag: %d\n", programpt->benchmode, programpt->strategy, programpt->strategy != STRATEGIES_ADAPTIVE);
	printf("ints_start_from: %d\nremaining_args: %d\n", ints_start_from, ac - ints_start_from);
	if ((ac - ints_start_from) == 0)
		fail();
	
	stack_apt->name = 'a';
	printf("%c", stack_apt->name);
		// Parse the remaining args, supposedly numbers. check for errors.
}
