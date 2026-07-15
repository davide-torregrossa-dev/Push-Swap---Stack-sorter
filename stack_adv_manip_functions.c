/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_adv_manip_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:39:37 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/14 13:41:53 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_realign(t_stack *stackpt)
{
	r(stackpt, -stackpt->offset);
}

void	r_goto_index(t_stack *stackpt, int index)
{
	int	steps;

	steps = stackpt->current_size - index;
	if (index < stackpt->current_size / 2)
		steps = -index;
	r(stackpt, steps);
}

void	p_pour(t_stack *stack_frompt, t_stack *stack_topt)
{
	while (stack_frompt->current_size != 0)
		p(stack_frompt, stack_topt);
}
