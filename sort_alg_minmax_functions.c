/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_minmax_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:00:36 by egarlasc          #+#    #+#             */
/*   Updated: 2026/07/06 16:24:25 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	minmax_push_maxfirst(t_stack *stack_frompt, t_stack *stack_topt)
{
		int	max_index;
		int	min_index;

		max_index = array_find_max_index(stack_frompt->content, stack_frompt->current_size);
		r_goto_index(stack_frompt, max_index);
		p(stack_frompt, stack_topt);
		min_index = array_find_min_index(stack_frompt->content, stack_frompt->current_size);
		r_goto_index(stack_frompt, min_index);
		p(stack_frompt, stack_topt);

}

static void	minmax_push_minfirst(t_stack *stack_frompt, t_stack *stack_topt)
{
	int	max_index;
	int	min_index;

	min_index = array_find_min_index(stack_frompt->content, stack_frompt->current_size);
	r_goto_index(stack_frompt, min_index);
	p(stack_frompt, stack_topt);
	max_index = array_find_max_index(stack_frompt->content, stack_frompt->current_size);
	r_goto_index(stack_frompt, max_index);
	p(stack_frompt, stack_topt);
	s(stack_topt);
}

void	minmax_do1step(t_stack *stack_frompt, t_stack *stack_topt)
{
	int	max_index;
	int	min_index;
	int *bestroute;
	int *minmaxindexes;

	max_index = array_find_max_index(stack_frompt->content, stack_frompt->current_size);
	min_index = array_find_min_index(stack_frompt->content, stack_frompt->current_size);
	minmaxindexes = malloc(2*sizeof(int));
	minmaxindexes[0] = max_index;
	minmaxindexes[1] = min_index;
	bestroute = router_get_best_order(stack_frompt, minmaxindexes, 2);
	if (bestroute[0] == min_index)
		minmax_push_minfirst(stack_frompt, stack_topt);
	else
		minmax_push_maxfirst(stack_frompt, stack_topt);

	free(minmaxindexes);
	r(stack_topt, -1);
}