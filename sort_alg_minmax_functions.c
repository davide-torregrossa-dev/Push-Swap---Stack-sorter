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
	int maxfirst_cost;
	int minfirst_cost;

	max_index = array_find_max_index(stack_frompt->content, stack_frompt->current_size);
	min_index = array_find_min_index(stack_frompt->content, stack_frompt->current_size);
	maxfirst_cost = rcost_goto_index(stack_frompt, 0, max_index);
	maxfirst_cost += rcost_goto_index(stack_frompt, max_index, min_index);
	minfirst_cost = rcost_goto_index(stack_frompt, 0, min_index);
	minfirst_cost += rcost_goto_index(stack_frompt, min_index, max_index);

	if (maxfirst_cost <= minfirst_cost)
		minmax_push_maxfirst(stack_frompt, stack_topt);
	else
		minmax_push_minfirst(stack_frompt, stack_topt);
	
	r(stack_topt, -1);
}


/*
void	minmax_do1step(t_stack *stack_apt, t_stack *stack_bpt)
{
	int	max_index;
	int	min_index;

	max_index = array_find_max_index(stack_apt->content, stack_apt->current_size);
	r_goto_index(stack_apt, max_index);
	p(stack_apt, stack_bpt);
	min_index = array_find_min_index(stack_apt->content, stack_apt->current_size);
	r_goto_index(stack_apt, min_index);
	p(stack_apt, stack_bpt);
	r(stack_bpt, -1);
}
*/