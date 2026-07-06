/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_functions_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:09:28 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/02 15:09:32 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_find_string(char **arr, int size, char *query)
{
	int	i;

	if (arr == NULL || query == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (string_equals(arr[i], query) == 1)
			return (i);
		i++;
	}
	return (-1);
}

int	*array_swap_indexes(int *arr, int i1, int i2)
{
	int	temp;

	temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
	return (arr);
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

int	*array_prepend(int *arr, int arr_size, int value)
{
	int	i;
	int	*out;

	out = malloc((arr_size + 1) * sizeof(int));
	if (!out)
		return (NULL);
	out[0] = value;
	i = 0;
	while (i < arr_size)
	{
		out[i + 1] = arr[i];
		i++;
	}
	free(arr);
	return (out);
}

int	*array_rm_index(int *arr, int arr_size, int index)
{
	int	i;
	int	*out;

	out = malloc((arr_size - 1) * sizeof(int));
	if (!out)
		return (NULL);
	i = 0;
	while (i < arr_size - 1)
	{
		out[i] = arr[i + (i >= index)];
		i++;
	}
	free(arr);
	return (out);
}

