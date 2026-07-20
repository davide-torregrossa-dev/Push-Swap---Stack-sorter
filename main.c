/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:06:25 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/19 13:06:26 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Trattare casi con <5 di size.
// integrare bench.
// vedere i vari leak e nullcheck.
static int	disorder_to_strategy(float disorder)
{
	if (disorder < 0.2)
		return (STRATEGIES_SIMPLE);
	else if (disorder < 0.5)
		return (STRATEGIES_MEDIUM);
	return (STRATEGIES_COMPLEX);
}

static void	bench_init(t_bench *benchpt, float disorder, int CLI_strategy)
{
	benchpt->pa = 0;
	benchpt->pb = 0;
	benchpt->sa = 0;
	benchpt->sb = 0;
	benchpt->ss = 0;
	benchpt->ra = 0;
	benchpt->rra = 0;
	benchpt->rb = 0;
	benchpt->rrb = 0;
	benchpt->rr = 0;
	benchpt->rrr = 0;
	benchpt->strategy = CLI_strategy;
	benchpt->strategy_is_from_adaptive = 0;
	benchpt->disorder = disorder;
}

char	*get_strategy_name(int strategy)
{
	if (strategy == 1)
		return ("O(n2)");
	if (strategy == 2)
		return ("O(n√n)");
	if (strategy == 3)
		return ("O(n log n)");
	return ("");
}

static int	bench_get_total_ops(t_bench bench)
{
	int	out;

	out = 0;
	out += bench.pa;
	out += bench.pb;
	out += bench.sb;
	out += bench.sa;
	out += bench.ra;
	out += bench.rb;
	out += bench.rra;
	out += bench.rrb;
	out += bench.rr;
	out += bench.rrr;
	return (out);
}

static void	bench_print_disorder(t_bench bench)
{
	float	pct;
	int		intt;
	int		decs;

	pct = bench.disorder * 100.0f;
	intt = (int)pct;
	decs = (int)((pct - intt) * 100);
	if (decs < 0)
		decs = -decs;
	printf("[bench] disorder: %d.%02d%%\n", intt, decs);
}

static void	bench_print(t_bench bench)
{
	if (!bench.is_active)
		return ;
	bench_print_disorder(bench);
	printf("[bench] strategy:");
	if (bench.strategy_is_from_adaptive)
		printf(" Adaptive \\");
	printf(" %s\n", get_strategy_name(bench.strategy));
	printf("[bench] total_ops: %d\n", bench_get_total_ops(bench));
	printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench.sa, bench.sb,
		bench.ss, bench.pa, bench.pb);
	printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d", bench.ra,
		bench.rb, bench.rr, bench.rra, bench.rrb, bench.rrr);
}

static void	free_the_stacks(t_stack *apt, t_stack *bpt)
{
	free(apt->content);
	free(bpt->content);
}

int	main(int ac, char **av)
{
	t_CLI_params	CLI_params;
	t_stack		a;
	t_stack		b;
	t_bench		bench;

	a.bench = &bench;
	b.bench = &bench;
	program_and_mainstack_init(av, ac, &CLI_params, &a);
	stack_init(&b, 'b', NULL, 0);
	bench_init(&bench, stack_calc_disorder(&a), CLI_params.strategy);
	if (CLI_params.strategy == STRATEGIES_ADAPTIVE
		|| CLI_params.strategy == STRATEGIES_ADAPTIVE_CLI)
	{
		bench.strategy = disorder_to_strategy(stack_calc_disorder(&a));
		bench.strategy_is_from_adaptive = 1;
	}
	if (CLI_params.strategy == STRATEGIES_SIMPLE)
		minmax(&a, &b); // leaks ok
	else if (CLI_params.strategy == STRATEGIES_MEDIUM)
		bucketsort(&a, &b, bucketsort_init(&a));
	else
		radix_sort(&a, &b); // leaks ok
	
	printf("%d\n", bench.strategy);	
	bench_print(bench);
	free_the_stacks(&a, &b);
}
