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
static int	disorder_to_strategy(double disorder)
{
	if (disorder < 0.2)
		return (STRATEGIES_SIMPLE);
	else if (disorder < 0.5)
		return (STRATEGIES_MEDIUM);
	return (STRATEGIES_COMPLEX);
}

int	main(int ac, char **av)
{
	t_program	program;
	t_stack		a;
	t_stack		b;

	program_and_stack_init(av, ac, &program, &a);
	stack_init(&b, 'b', NULL, 0);
	if (program.strategy == STRATEGIES_ADAPTIVE
		|| program.strategy == STRATEGIES_ADAPTIVE_CLI)
		program.strategy = disorder_to_strategy(stack_calc_disorder(&a));
	else if (program.strategy == STRATEGIES_SIMPLE)
		minmax(&a, &b); // leaks ok
	else if (program.strategy == STRATEGIES_MEDIUM)
		bucketsort(&a, &b, bucketsort_init(&a));
	else
		radix_sort(&a, &b); // leaks ok
	stack_print(a);
	free(a.content);
	free(b.content);
}
