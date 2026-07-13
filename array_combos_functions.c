#include "push_swap.h"



static void	ft_copy_row(t_combos *util, int *arr)
{
	int	i;

	util->result[util->current_row] = (int *)malloc(util->size * sizeof(int));
	if (!util->result[util->current_row])
		return ;
	i = 0;
	while (i < util->size)
	{
		util->result[util->current_row][i] = arr[i];
		i++;
	}
	util->current_row++;
}

void	ft_permute(int *arr, int start, t_combos *util)
{
	int	i;

	if (start == util->size - 1)
	{
		ft_copy_row(util, arr);
		return ;
	}
	i = start;
	while (i < util->size)
	{
		swap(&arr[start], &arr[i]);
		ft_permute(arr, start + 1, util);
		swap(&arr[start], &arr[i]);
		i++;
	}
}

int	**array_get_combos(int *arr, int size, int iterations)
{
	int			**result;
	t_combos	util;
	printf("%s", "perm");
	result = (int **)malloc(iterations * sizeof(int *));
	if (!result)
		return (NULL);
	util.result = result;
	util.current_row = 0;
	util.size = size;
	ft_permute(arr, 0, &util);
	return (result);
}