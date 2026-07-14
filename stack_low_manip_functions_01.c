/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_low_manip_functions_01.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:38:48 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/14 13:38:49 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rotate(t_stack *stackpt, int dir)
{
	stackpt->content = array_rotate(stackpt->content, stackpt->current_size,
			dir);
	stackpt->offset -= dir;
}
