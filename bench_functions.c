/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:04:52 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/21 13:01:23 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	disorder_to_strategy(float disorder)
{
	if (disorder < 0.2)
		return (STRATEGIES_SIMPLE);
	else if (disorder < 0.5)
		return (STRATEGIES_MEDIUM);
	return (STRATEGIES_COMPLEX);
}

void	bench_init(t_bench *benchpt, float disorder, int CLI_strategy)
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
	if (CLI_strategy == STRATEGIES_ADAPTIVE
		|| CLI_strategy == STRATEGIES_ADAPTIVE_CLI)
	{
		benchpt->strategy = disorder_to_strategy(disorder);
		benchpt->strategy_is_from_adaptive = 1;
	}
}
