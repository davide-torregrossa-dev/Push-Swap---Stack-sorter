/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_bucket_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:54:49 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/19 17:24:54 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_bucket_range_gap(t_stack *stackpt, int nbuckets)
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

t_stack	*bucketsort_init(t_stack *stackpt)
{
	t_stack	*buckets;
	int		brg;
	int		nbuckets;

	nbuckets = ft_sqrt(stackpt->current_size);
	if (nbuckets < 1)
		nbuckets = 1;
	brg = calculate_bucket_range_gap(stackpt, nbuckets);
	buckets = malloc(sizeof(t_stack) * (nbuckets + 1));
	if (!buckets)
	{
		/* free su malloc precedenti*/
		exit(1);
	}
	fill_the_buckets(stackpt, brg, buckets, nbuckets);
	stack_init(&buckets[nbuckets], '\0', NULL, 0);
	return (buckets);
}

void	bucketsort(t_stack *tosortpt, t_stack *second_stackpt, t_stack *buckets)
{
	int	bi;
	int	i;
	int	idx;
	int	size;
	int	temp;

	bi = 0;
	while (buckets[bi + 1].name)
		bi++;
	while (bi != -1)
	{
		i = 0;
		while (i < buckets[bi].current_size)
		{
			size = tosortpt->current_size;
			idx = array_find_int(tosortpt->content, size,
					buckets[bi].content[i]);
			r_goto_index(tosortpt, idx);
			p(tosortpt, second_stackpt);
			i++;
		}
		if (i != 0)
		{
			temp = array_find_int(tosortpt->content, size, temp);
			r_goto_index(tosortpt, temp);
		}
		while (second_stackpt->current_size != 0)
		{
			idx = array_find_max_index(second_stackpt->content,
					second_stackpt->current_size);
			r_goto_index(second_stackpt, idx);
			p(second_stackpt, tosortpt);
		}
		temp = tosortpt->content[0];
		bi--;
	}
}
