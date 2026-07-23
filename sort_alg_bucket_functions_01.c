/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_bucket_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:54:49 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/21 10:24:45 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	buckets_free(t_stack *buckets)
{
	int	bi;

	bi = 0;
	while (buckets[bi].name)
	{
		free(buckets[bi].content);
		bi++;
	}
	free(buckets);
}

t_stack	*bucketsort_init(t_stack *stackpt, t_stack *bstackpt)
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
		free(stackpt->content);
		free(bstackpt->content);
		buckets_free(buckets);
		exit(1);
	}
	fill_the_buckets(stackpt, brg, buckets, nbuckets);
	stack_init(&buckets[nbuckets], '\0', NULL, 0);
	return (buckets);
}

static void	put_bucketnums_in_stackb(t_stack bucket, t_stack *tosortpt,
		t_stack *second_stackpt)
{
	int	i;
	int	idx;

	i = 0;
	while (i < bucket.current_size)
	{
		idx = array_find_int(tosortpt->content, tosortpt->current_size,
				bucket.content[i]);
		r_goto_index(tosortpt, idx);
		p(tosortpt, second_stackpt);
		i++;
	}
}

void	bucketsort(t_stack *tosortpt, t_stack *second_stackpt, t_stack *buckets)
{
	int	bi;
	int	idx;
	int	first_idx_content;

	bi = 0;
	while (buckets[bi + 1].name)
		bi++;
	first_idx_content = tosortpt->content[0];
	while (bi != -1)
	{
		put_bucketnums_in_stackb(buckets[bi], tosortpt, second_stackpt);
		first_idx_content = array_find_int(tosortpt->content,
				tosortpt->current_size, first_idx_content);
		r_goto_index(tosortpt, first_idx_content);
		while (second_stackpt->current_size != 0)
		{
			idx = array_find_max_index(second_stackpt->content,
					second_stackpt->current_size);
			r_goto_index(second_stackpt, idx);
			p(second_stackpt, tosortpt);
		}
		first_idx_content = tosortpt->content[0];
		bi--;
	}
	buckets_free(buckets);
}
