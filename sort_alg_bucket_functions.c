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

int calculate_bucket_range(t_stack *stackpt)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (i < stackpt->current_size)
    {
        res += stackpt->content[i];
        i++;
    }
    return (res / stackpt->current_size);
}

int **bucketsort_init(t_stack *stackpt)
{
    int bucket_range;
    int bucket_i;
    int i;
    int curr_bucket_len;
    int nbuckets;
    int **buckets;

    nbuckets = 5;
    bucket_i = 0;
    
    bucket_range = calculate_bucket_range(stackpt);
    buckets = malloc(sizeof(int *) * nbuckets);
    if (!buckets)
        exit(1);
    while (bucket_i < nbuckets)
    {
        curr_bucket_len = 0;
        i = 0;
        buckets[bucket_i] = malloc(0);
        if (!buckets[bucket_i])
            exit(1);
        while (i < stackpt->current_size)
        {
            if (stackpt->content[i] < bucket_range * (bucket_i + 1))
            {
                buckets[bucket_i] = array_append(buckets[bucket_i], curr_bucket_len, stackpt->content[i]);
                curr_bucket_len++;
            }
            i++;
        }
        bucket_i++;
    }
    return (buckets);
}

int	*array_append(int *arr, int arr_size, int value)
{
	int	i;
	int	*out;

	out = malloc((arr_size + 1) * sizeof(int));
	if (!out)
		return (NULL);
	i = 0;
	while (i < arr_size)
	{
		out[i] = arr[i];
		i++;
	}
	out[i] = value;
	free(arr);
	return (out);
}