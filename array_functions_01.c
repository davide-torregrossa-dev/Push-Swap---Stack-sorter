/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_functions_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:02:59 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/19 13:03:01 by dtorregr         ###   ########.fr       */
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

int	array_find_min_index(int *arr, int size)
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

int 	*array_duplicate(int *arr, int size)
{
	int	i;
	int *destarr;

	destarr = malloc(size * sizeof(int));
	if (!destarr)
		return NULL;
	i = 0;
	while (i < size)
	{
		destarr[i] = arr[i];
		i++;
	}
	return destarr;
}
