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

void	minmax_apply(t_stack *stack_apt)
{
	int	max;
	int	min;

	max = array_get_max_index(stack_apt->content, stack_apt->current_size);
	min = array_get_min_index(stack_apt->content, stack_apt->current_size);

}
