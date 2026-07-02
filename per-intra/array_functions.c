/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_functions.c                                  :+:      :+:    :+:   */
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
