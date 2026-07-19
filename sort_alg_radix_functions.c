/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_radix_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:56:13 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/19 16:57:06 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_to_bits(int n)
{
	int	bits;

	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	bits = 0;
	while (n > 0)
	{
		bits++;
		n >>= 1;
	}
	return (bits);
}

static void	radix_sort_loop(int max_bits, t_stack *tosortpt,
		t_stack *second_stackpt)
{
	int	i;
	int	j;
	int	top_value;
	int	size;

	i = 0;
	while (i < max_bits)
	{
		size = tosortpt->current_size;
		j = 0;
		while (j < size)
		{
			top_value = tosortpt->content[0];
			if (((top_value >> i) & 1) == 0)
				p(tosortpt, second_stackpt);
			else
				r(tosortpt, -1);
			j++;
		}
		p_pour(second_stackpt, tosortpt);
		i++;
	}
}

void	radix_sort(t_stack *tosortpt, t_stack *second_stackpt)
{
	int	max_idx;
	int	max_val;

	if (tosortpt->current_size <= 1)
		return ;
	max_idx = array_find_max_index(tosortpt->content, tosortpt->current_size);
	max_val = tosortpt->content[max_idx];
	radix_sort_loop(int_to_bits(max_val), tosortpt, second_stackpt);
}
