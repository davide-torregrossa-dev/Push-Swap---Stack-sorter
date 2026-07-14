/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zOLD.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:38:00 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/14 13:38:01 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// stack_swap_indexes è rotta.
// non toccare array_rotate, ora funziona!
// Integrare pivot e safenums (o sorter struct).
// scrivere e integrare RRR!;

//-------------------BASIC STACK MANIP FUNCS

/*
void	rrr(t_stack *stack_apt, t_stack *stack_bpt, int times) {
	int dir;

	dir = ((times < 0)*2)-1;
	while (times != 0) {
		printf("rrr->");
		r(stack_bpt, times);
		printf("rrr->");
		r(stack_bpt, times);
		times += dir;
	}
}
*/

//-------------------ADV STACK MANIP FUNCS

void	stack_swap_indexes(t_stack *mainpt, t_stack *stachept, int i1, int i2)
{
	int	temp;
	int	r2;

	if (!mainpt || mainpt->current_size < 2 || i1 == i2)
		return ;
	if (i1 < 0 || i1 >= mainpt->current_size || i2 < 0
		|| i2 >= mainpt->current_size)
		return ;
	if (i1 > i2)
	{
		temp = i1;
		i1 = i2;
		i2 = temp;
	}
	r(mainpt, i1);
	p(mainpt, stachept);
	r2 = i2 - i1 - 1;
	r(mainpt, r2);
	p(mainpt, stachept);
	s(stachept);
	p(stachept, mainpt);
	r(mainpt, -r2);
	r(mainpt, -i1);
	p(stachept, mainpt);
}
