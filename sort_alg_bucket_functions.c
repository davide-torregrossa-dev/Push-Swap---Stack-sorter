/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_bucket_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:26:08 by egarlasc          #+#    #+#             */
/*   Updated: 2026/07/07 17:26:11 by egarlasc         ###   ########.fr       */
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
	int	refsize;
	int	foundat;

	i = 0;
	refsize = ref->current_size;
	while (i < bucket->current_size)
	{
		query = bucket->content[i];
		foundat = array_find_int(ref->content, refsize, query);
		if (foundat != -1)
			stack_rm_index(bucket, i);
		i++;
	}
}

t_stack	*bucketsort_init(t_stack *stackpt)
{
	t_stack	*buckets;
	int		brg;
	int		bucket_i;
	int		nbuckets;

	nbuckets = ft_sqrt(stackpt->current_size);
	brg = calculate_bucket_range_gap(stackpt, nbuckets);
	buckets = malloc(sizeof(t_stack) * (nbuckets));
	if (!buckets)
	{
		// free su malloc precedenti (smalloc)
		exit(1);
	}
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
	buckets[nbuckets].name = '\0';
	return (buckets);
}

void	bucketsort_loop(t_stack *tosortpt, t_stack *second_stackpt,
		t_stack *buckets)
{
	int	bi;
	int	i;
	int	idx;
	int	size;
	int	temp;
	stack_print(*tosortpt);
	bi = 0;
	while (buckets[bi + 1].name)
		bi++;
	while (bi != -1)
	{
		// buckets[bi].content = router_get_best_order(tosortpt,
		//		buckets[bi].content, buckets[bi].current_size);
		i = 0;
		stack_print(buckets[bi]);
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
