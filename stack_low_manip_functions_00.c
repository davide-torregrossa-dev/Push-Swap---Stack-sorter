/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_low_manip_functions_00.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:38:56 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/14 13:38:57 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *stackpt, char name, int *content, int size)
{
	if (content == NULL)
	{
		content = malloc(0);
		if (!content)
			exit(1);
		size = 0;
	}
	stackpt->name = name;
	stackpt->content = content;
	stackpt->current_size = size;
	stackpt->offset = 0;
}

void	stack_print(t_stack stack)
{
	int	i;

	i = 0;
	printf("------[ %c ]------\n", stack.name - 32);
	printf("|curr_size: %d \t|\n", stack.current_size);
	printf("|offset: %d\t|\n", stack.offset);
	printf("-----------------\n");
	while (i < stack.current_size)
	{
		printf("|%c%d\t%d\t|\n", stack.name - 32, i, stack.content[i]);
		i++;
	}
	printf("-----------------\n");
}

void	stack_append(t_stack *stackpt, int value)
{
	stackpt->content = array_append(stackpt->content, stackpt->current_size,
			value);
	stackpt->current_size++;
}

void	stack_prepend(t_stack *stackpt, int value)
{
	stackpt->content = array_prepend(stackpt->content, stackpt->current_size,
			value);
	stackpt->current_size++;
}

void	stack_rm_index(t_stack *stackpt, int index)
{
	stackpt->content = array_rm_index(stackpt->content, stackpt->current_size,
			index);
	stackpt->current_size--;
}
