/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_functions_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:45:51 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/19 13:03:39 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	seedgen(unsigned int *seed)
{
	*seed = *seed * 1103515245 + 12345;
	return ((int)(*seed / 65536) % 32768);
}

void	array_shuffle(int *arr, int size, int seed)
{
	int				i;
	int				j;
	int				temp;
	unsigned int	current_seed;

	if (!arr || size <= 1)
		return ;
	current_seed = (unsigned int)seed;
	i = size - 1;
	while (i > 0)
	{
		j = seedgen(&current_seed) % (i + 1);
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i--;
	}
}

int	**array_get_rcombos(int *arr, int size, int iterations)
{
	int	**result;
	int	i;

	result = (int **)malloc(iterations * sizeof(int *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < iterations)
	{
		result[i] = malloc(sizeof(int) * size);
		array_duplicate(arr, result[i], size);
		if (i)
			array_shuffle(result[i], size, i);
		i++;
	}
	return (result);
}

int	array_is_sorted(int *array, int array_size)
{
	int	i;

	if (!array || array_size <= 1)
		return (1);
	i = 0;
	while (i < array_size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}