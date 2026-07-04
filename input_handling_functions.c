/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:11:10 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/03 17:53:39 by egarlasc         ###   ########.fr       */
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

int	atoi_check(const char *nptr)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if(nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
		fail();
	return ((int)num);
}

int	*atoi_batch_string(char **strings)
{
	int	i;
	int	*out;

	i = 0;
	while (strings[i])
	{
		if (string_is_number(strings[i]) != 1)
			fail();
		i++;
	}
	out = malloc(i * sizeof(int));
	if (!out)
		exit(1);
	i = 0;
	while (strings[i])
	{
		out[i] = atoi_check(strings[i]);
		i++;
	}
	return (out);
}

void	program_and_stack_init(char **av, int ac, t_program *programpt,
		t_stack *stack_apt)
{
	int	ints_start_from;
	int *stack_content;
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
	
	stack_content = atoi_batch_string(&av[ints_start_from]);
	stack_init(stack_apt, 'a', stack_content, ac-ints_start_from);
}
