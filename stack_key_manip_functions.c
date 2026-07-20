/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_key_manip_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:39:18 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/14 13:39:19 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stackpt)
{
	if (stackpt->current_size >= 2)
	{
		printf("s%c\n", stackpt->name);
		stackpt->content = array_swap_indexes(stackpt->content, 0, 1);
		if (stackpt->name == 'a')
			stackpt->bench->sa++;
		else if (stackpt->name == 'b')
			stackpt->bench->sb++;
	}
}

void	p(t_stack *from_stackpt, t_stack *to_stackpt)
{
	if (from_stackpt->current_size != 0)
	{
		printf("p%c\n", from_stackpt->name);
		stack_prepend(to_stackpt, from_stackpt->content[0]);
		stack_rm_index(from_stackpt, 0);
		if (from_stackpt->name == 'a')
			from_stackpt->bench->pa++;
		else if (from_stackpt->name == 'b')
			from_stackpt->bench->pb++;
	}
}

static int	*r_msg_to_op_ptr(t_stack *stackpt, char *msg)
{
	if (string_equals(msg, "r%c\n"))
	{
		if (stackpt->name == 'a')
			return (&stackpt->bench->ra);
		if (stackpt->name == 'b')
			return (&stackpt->bench->rb);
	}
	if (string_equals(msg, "rr%c\n"))
	{
		if (stackpt->name == 'a')
			return (&stackpt->bench->rra);
		else if (stackpt->name == 'b')
			return (&stackpt->bench->rrb);
	}
	return (NULL);
}

void	r(t_stack *stackpt, int times)
{
	int		dir;
	char	*msg;
	int		*op_ptr;

	msg = "r%c\n";
	if (times < 0)
		msg = "rr%c\n";
	dir = ((times < 0) * 2) - 1;
	while (times != 0)
	{
		op_ptr = r_msg_to_op_ptr(stackpt, msg);
		(*op_ptr)++;
		printf(msg, stackpt->name);
		stack_rotate(stackpt, dir);
		times += dir;
	}
}
