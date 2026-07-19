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

double	stack_calc_disorder(t_stack *stack_apt)
{
	int		i;
	int		j;
	double	mistakes;
	double	total_pairs;
	int		size;

	size = stack_apt->current_size;
	if (size < 2)
		return (0.0);
	mistakes = 0.0;
	total_pairs = 0.0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1.0;
			if (stack_apt->content[i] > stack_apt->content[j])
				mistakes += 1.0;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
