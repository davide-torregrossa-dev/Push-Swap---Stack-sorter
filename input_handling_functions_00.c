/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_functions_00.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:03:56 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/21 10:06:36 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	atoi_check(const char *nptr)
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
	else if (nptr[i] == '+')
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

static int	*atoi_batch_string(char **strings)
{
	int	i;
	int	*out;
	int	n;

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
		n = atoi_check(strings[i]);
		if (array_find_int(out, i, n) != -1)
			fail();
		out[i] = n;
		i++;
	}
	return (out);
}

void	program_and_mainstack_init(char **av, int ac,
		t_cli_params *CLI_paramspt, t_stack *stack_apt)
{
	int	ints_start_from;
	int	*stack_content;
	char **normalized_args;
	if (ac == 1)
		exit(1);
	CLI_paramspt->benchmode = string_equals(av[1], "--bench");
	stack_apt->bench->is_active = CLI_paramspt->benchmode;
	CLI_paramspt->strategy = STRATEGIES_ADAPTIVE;
	CLI_paramspt->strategy = input_get_strategy(av, CLI_paramspt->benchmode);
	ints_start_from = 1 + CLI_paramspt->benchmode
		+ (CLI_paramspt->strategy != STRATEGIES_ADAPTIVE);
	if ((ac - ints_start_from) == 0)
		fail();
	normalized_args = ft_split(av[ints_start_from], ' ');
	stack_content = atoi_batch_string(normalized_args);
	free(normalized_args);
	stack_init(stack_apt, 'a', stack_content, ac - ints_start_from);
}


void	fail(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
