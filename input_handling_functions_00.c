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

static void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

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
		if (!string_is_number(strings[i]))
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
		{
			free(out);
			fail();
		}
		out[i] = n;
		i++;
	}
	return (out);
}

static void	process_space_arg(char *arg, t_stack *stack_apt)
{
	char	**tokens;
	int		size;
	int		*content;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		fail();
	size = 0;
	while (tokens[size])
		size++;
	content = atoi_batch_string(tokens);
	free_split(tokens);
	stack_init(stack_apt, 'a', content, size);
}

void	program_and_mainstack_init(char **av, int ac,
		t_cli_params *CLI_paramspt, t_stack *stack_apt)
{
	int	ints_start_from;
	int	n_args;
	int	*stack_content;
	int	stack_size;

	if (ac == 1)
		exit(1);
	CLI_paramspt->benchmode = string_equals(av[1], "--bench");
	stack_apt->bench->is_active = CLI_paramspt->benchmode;
	CLI_paramspt->strategy = STRATEGIES_ADAPTIVE;
	CLI_paramspt->strategy = input_get_strategy(av, CLI_paramspt->benchmode);
	ints_start_from = 1 + CLI_paramspt->benchmode
		+ (CLI_paramspt->strategy != STRATEGIES_ADAPTIVE);
	n_args = ac - ints_start_from;
	if (n_args == 1 && string_has_space(av[ints_start_from]))
	{
		process_space_arg(av[ints_start_from], stack_apt);
		return ;
	}
	stack_size = n_args;
	stack_content = atoi_batch_string(&av[ints_start_from]);
	stack_init(stack_apt, 'a', stack_content, stack_size);
}
