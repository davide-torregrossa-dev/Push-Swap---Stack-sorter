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