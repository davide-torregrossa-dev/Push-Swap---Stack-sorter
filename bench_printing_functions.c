/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_printing_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:00:29 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/21 13:00:59 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static char	*get_strategy_name(int strategy)
{
	if (strategy == 1)
		return ("O(n2)");
	if (strategy == 2)
		return ("O(n√n)");
	if (strategy == 3)
		return ("O(n log n)");
	if (strategy == 42)
		return ("<=5 size. Using a custom solution.");
	if (strategy == 100)
		return ("Numbers were already sorted, nothing to do.");
	return ("");
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
	ft_printf("[bench] disorder: %d.", intt);
	if (decs < 10)
		ft_printf("0%d", decs);
	else
		ft_printf("%d", decs);
	ft_printf("%%\n");
}

void	bench_print(t_bench bench)
{
	if (!bench.is_active)
		return ;
	bench_print_disorder(bench);
	ft_printf("[bench] strategy:");
	if (bench.strategy_is_from_adaptive)
		ft_printf(" Adaptive \\");
	else
		ft_printf(" Forced");
	ft_printf(" %s\n", get_strategy_name(bench.strategy));
	ft_printf("[bench] total_ops: %d\n", bench_get_total_ops(bench));
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench.sa,
		bench.sb, bench.ss, bench.pa, bench.pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d", bench.ra,
		bench.rb, bench.rr, bench.rra, bench.rrb, bench.rrr);
}
