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

int	array_find_string(char **arr, char *query)
{
	int	i;

	if (arr == NULL || query == NULL)
		return (0);
	i = 0;
	while (arr[i] != NULL)
	{
		if (string_equals(arr[i], query) == 1)
			return (i);
		i++;
	}
	return (-1);
}
