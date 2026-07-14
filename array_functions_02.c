/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_functions_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:45:51 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/14 13:47:04 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
