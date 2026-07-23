/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_radix_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:56:13 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/23 11:58:44 by dtorregr         ###   ########.fr       */
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
		t_stack *second_stackpt, int min_val)
{
	int				i;
	int				j;
	int				size;
	unsigned int	top_value;

	i = 0;
	while (i < max_bits)
	{
		size = tosortpt->current_size;
		j = 0;
		while (j < size)
		{
			top_value = (unsigned int)(tosortpt->content[0] - min_val);
			if (((top_value >> i) & 1u) == 0u)
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
	int	min_idx;
	int	min_val;
	int	max_bits;

	if (tosortpt->current_size <= 1)
		return ;
	max_idx = array_find_max_index(tosortpt->content, tosortpt->current_size);
	max_val = tosortpt->content[max_idx];
	min_idx = array_find_min_index(tosortpt->content, tosortpt->current_size);
	min_val = tosortpt->content[min_idx];
	max_bits = int_to_bits(max_val - min_val);
	radix_sort_loop(max_bits, tosortpt, second_stackpt, min_val);
}
