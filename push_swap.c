#include "push_swap.h"

typedef struct s_stack
{
	int *content;
	int current_size;
}	t_stack;

//void 



//void stack_swap_indexes(t_stack main, t_stack stache, i1, i2)
//{
	

//}

//------------------------------ Tests e simili

void array_swap_indexes(int **arr, int i1, int i2) {
	int	temp;
	
	temp = (*arr)[i1];
	(*arr)[i1] = (*arr)[i2];
	(*arr)[i2] = temp;
}

int random_int(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void stack_init(t_stack *stack, int size, int minstep, int maxstep, int shuffles) {
	int i = 0;
	int content = 0;
	
	srand(time(NULL));
	stack->content = malloc(size * sizeof(int));
	if (stack->content == NULL)
		return;
	while (i < size) {
		content += random_int(minstep, maxstep);	
		stack->content[i] = content;
		i++;
	}
	stack->current_size = size;
	i = 0;
	while (i < shuffles) {
		array_swap_indexes(&(stack->content), random_int(0, size-1), random_int(0, size-1));
		i++;
	}
}

void stack_print(t_stack stack)
{
	int i;

	i = 0;
	while (i < stack.current_size) {	
		printf("%d\n", stack.content[i]);
		i++;
	}
}

//---------------------------------------------------MAIN
int main() {
	t_stack a;
	t_stack b;
	int a_size;

	a_size = 50;
	stack_init(&(a), a_size, 1, 10, a_size*2);
	if (!a.content)
		return 0;

	b.content = NULL;
	b.current_size = 0;
	
	stack_print(a);
}
