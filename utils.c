#include "push_swap.h"

int random_int(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void stack_swap_indexes(int **stack, int i1, int i2) {
	int	temp;
	
	temp = (*stack)[i1];
	(*stack)[i1] = (*stack)[i2];
	(*stack)[i2] = temp;
}

void stack_create(int **ptr, int size, int minstep, int maxstep, int shuffles) {
	int i = 0;
	int content = 0;
	
	*ptr = malloc(size * sizeof(int));
	if (*ptr == NULL)
		return;

	while (i < size) {
		content += random_int(minstep, maxstep);	
		(*ptr)[i] = content;
		i++;
	}

	i = 0;
	while (i < shuffles) {
		stack_swap_indexes(ptr, random_int(0, size-1), random_int(0, size-1));
		i++;
	}
}

int main() {
	int *stack;
	int stack_size = 10;
	int i = 0;

	srand(time(NULL));
	stack_create(&stack, stack_size, 1, 10, 25);
	if (!stack)
		return 0;

	while (i < stack_size) {	
		printf("%d\n", stack[i]);
		i++;
	}
}
