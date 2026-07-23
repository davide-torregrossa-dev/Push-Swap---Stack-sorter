/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:06:25 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/21 15:58:49 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_the_stacks(t_stack *apt, t_stack *bpt)
{
	free(apt->content);
	free(bpt->content);
}

static void	sort_trio(t_stack *apt)
{
	int	max_at_index;

	max_at_index = array_find_max_index(apt->content, apt->current_size);
	if (max_at_index == 0)
		r(apt, -1);
	else if (max_at_index == 1)
		r(apt, 1);
	if (apt->content[0] > apt->content[1])
		s(apt);
}

static void	sort_quad_or_more(t_stack *apt, t_stack *bpt)
{
	int	min_at_index;
	int	i;

	i = 1 - (apt->current_size == 5);
	while (i != 2)
	{
		min_at_index = array_find_min_index(apt->content, apt->current_size);
		r_goto_index(apt, min_at_index);
		p(apt, bpt);
		i++;
	}
	sort_trio(apt);
	p_pour(bpt, apt);
}

static void	sort(t_bench *bench, t_stack *apt, t_stack *bpt)
{
	if (bench->strategy_is_from_adaptive && apt->current_size <= 5)
	{
		bench->strategy = 42;
		if (apt->current_size == 2 && apt->content[0] > apt->content[1])
			s(apt);
		else if (apt->current_size == 3)
			sort_trio(apt);
		else
			sort_quad_or_more(apt, bpt);
		return ;
	}
	if (bench->strategy == STRATEGIES_SIMPLE)
		minmax(apt, bpt);
	else if (bench->strategy == STRATEGIES_MEDIUM)
		bucketsort(apt, bpt, bucketsort_init(apt, bpt));
	else
		radix_sort(apt, bpt);
}

int	main(int ac, char **av)
{
	t_cli_params	cli_params;
	t_stack			a;
	t_stack			b;
	t_bench			bench;

	a.bench = &bench;
	b.bench = &bench;
	program_and_mainstack_init(av, ac, &cli_params, &a);
	stack_init(&b, 'b', NULL, 0);
	bench_init(&bench, stack_calc_disorder(&a), cli_params.strategy);
	if (bench.strategy_is_from_adaptive)
	{
		if (!array_is_sorted(a.content, a.current_size))
			sort(&bench, &a, &b);
		else
			bench.strategy = 100;
	}
	else
		sort(&bench, &a, &b);
	stack_print(a);
	bench_print(bench);
	free_the_stacks(&a, &b);
}

// aggiustare makefile
// fixare print del bench to stderr
// vedere tutti i nullcheck