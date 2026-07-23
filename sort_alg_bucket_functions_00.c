/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_bucket_functions_00.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:46:42 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/21 12:46:44 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_bucket_range_gap(t_stack *stackpt, int nbuckets)
{
	int	min;
	int	max;

	min = array_find_min_index(stackpt->content, stackpt->current_size);
	min = stackpt->content[min];
	max = array_find_max_index(stackpt->content, stackpt->current_size);
	max = stackpt->content[max];
	return ((max - min) / (nbuckets - 1));
}

static void	bucket_fill(t_stack *stackpt, t_stack *bucketpt, int rmin, int rmax)
{
	int	i;

	i = stackpt->current_size - 1;
	while (i > -1)
	{
		if (int_in_range(stackpt->content[i], rmin, rmax))
			stack_append(bucketpt, stackpt->content[i]);
		i--;
	}
}

static void	bucket_remove_duplicates(t_stack *bucket, t_stack *ref)
{
	int	i;
	int	query;
	int	foundat;

	i = 0;
	while (i < bucket->current_size)
	{
		query = bucket->content[i];
		foundat = array_find_int(ref->content, ref->current_size, query);
		if (foundat != -1)
		{
			stack_rm_index(bucket, i);
		}
		else
			i++;
	}
}

void	fill_the_buckets(t_stack *stackpt, int brg, t_stack *buckets,
		int nbuckets)
{
	int	bucket_i;

	bucket_i = 0;
	while (bucket_i < nbuckets)
	{
		stack_init(&buckets[bucket_i], 'z', NULL, 0);
		bucket_fill(stackpt, &buckets[bucket_i], brg * bucket_i, brg * (bucket_i
				+ 1));
		if (bucket_i != 0)
			bucket_remove_duplicates(&buckets[bucket_i], &buckets[bucket_i
				- 1]);
		bucket_i++;
	}
}
