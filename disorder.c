/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:30:55 by egarlasc          #+#    #+#             */
/*   Updated: 2026/07/03 18:06:11 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_disorder(t_stack *stack_apt)
{
	int	i;
	int	j;
	double mistakes;
	double total_pairs;
	int size;

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
