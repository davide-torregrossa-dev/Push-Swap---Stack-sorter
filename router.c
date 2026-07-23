/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:44:19 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/19 13:19:45 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	router_calc_lanecost(t_stack *stackpt, int from_index,
		int target_index)
{
	int	size;
	int	virtual_index;
	int	steps;

	size = stackpt->current_size;
	virtual_index = target_index - from_index;
	if (virtual_index < 0)
		virtual_index += size;
	steps = size - virtual_index;
	if (virtual_index < size / 2)
		steps = -virtual_index;
	return (ft_abs(steps));
}

static int	router_calc_routecost(t_stack *stackpt, int *stops, int stops_size)
{
	int	cost;
	int	i;
	int	*indexes;

	indexes = malloc(sizeof(int) * stops_size);
	if (!indexes)
		return (-1);
	i = 0;
	while (i < stops_size)
	{
		indexes[i] = array_find_int(stackpt->content, stackpt->current_size,
				stops[i]);
		i++;
	}
	cost = 0;
	cost += router_calc_lanecost(stackpt, 0, indexes[0]);
	i = 0;
	while (i < stops_size - 1)
	{
		cost += router_calc_lanecost(stackpt, indexes[i], indexes[i + 1]);
		i++;
	}
	free(indexes);
	return (cost);
}

static void	combos_free(int **combos, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(combos[i]);
		i++;
	}
	free(combos);
}

static int	router_find_cheapest_combo(t_stack *stackpt, int **combos,
		int combos_amt, int stops_size)
{
	int	i;
	int	best_is_at_index;

	i = 0;
	best_is_at_index = 0;
	while (i < combos_amt)
	{
		if (router_calc_routecost(stackpt, combos[i],
				stops_size) < router_calc_routecost(stackpt,
				combos[best_is_at_index], stops_size))
			best_is_at_index = i;
		i++;
	}
	return (best_is_at_index);
}

int	*router_get_best_order(t_stack *stackpt, int *stops, int stops_size)
{
	int	combos_amt;
	int	**combos;
	int	best_is_at_index;
	int	*out;

	best_is_at_index = 0;
	combos_amt = 25;
	if (stops_size <= 7)
		combos_amt = factorialof(stops_size);
	combos = array_get_rcombos(stops, stops_size, combos_amt);
	best_is_at_index = router_find_cheapest_combo(stackpt, combos, combos_amt,
			stops_size);
	out = array_duplicate(combos[best_is_at_index], stops_size);
	combos_free(combos, combos_amt);
	return (out);
}
