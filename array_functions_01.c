/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_functions_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:50:34 by egarlasc          #+#    #+#             */
/*   Updated: 2026/07/06 15:59:37 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*array_rotate(int *arr, int arr_size, int dir)
{
	int	i;
	int	temp;

	if (arr == NULL || arr_size <= 1)
		return (arr);
	if (dir == 1)
	{
		temp = arr[0];
		i = -1;
		while (++i < arr_size - 1)
			arr[i] = arr[i + 1];
		arr[arr_size - 1] = temp;
	}
	else
	{
		temp = arr[arr_size - 1];
		i = arr_size;
		while (--i > 0)
			arr[i] = arr[i - 1];
		arr[0] = temp;
	}
	return (arr);
}

int	array_find_int(int *arr, int size, int query)
{
	int	i;

	if (arr == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (arr[i] == query)
			return (i);
		i++;
	}
	return (-1);
}

int	array_find_min_index(int *arr,int size)
{
	int	mini;
	int	i;

	i = 0;
	mini = i;
	while (i < size)
	{
		if (arr[mini] > arr[i])
			mini = i;
		i++;
	}
	return (mini);
}

int	array_find_max_index(int *arr, int size)
{
	int	maxi;
	int	i;

	i = 0;
	maxi = i;
	while (i < size)
	{
		if (arr[maxi] < arr[i])
			maxi = i;
		i++;
	}
	return (maxi);
}

void array_duplicate(int *arr, int *destarr, int size)
{
	int i;
	
	i = 0;
	while(i < size) {
		destarr[i] = arr[i];
		i++;
	}
}

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