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

void	minmax_do1step(t_stack *stack_apt, t_stack *stack_bpt)
{
	int	max_index;
	int	min_index;

	max_index = array_find_max_index(stack_apt->content, stack_apt->current_size);
	r_goto_index(stack_apt, max_index, 0);
	p(stack_apt, stack_bpt);
	min_index = array_find_min_index(stack_apt->content, stack_apt->current_size);
	r_goto_index(stack_apt, min_index, 0);
	p(stack_apt, stack_bpt);
	r(stack_bpt, -1);
}
