#include "push_swap.h"
//

typedef struct s_stack
{
	int *content;
	int current_size;
}	t_stack;


//-------------------ARRAY FUNCS
void array_swap_indexes(int **arr, int i1, int i2) {
	int	temp;
	
	temp = (*arr)[i1];
	(*arr)[i1] = (*arr)[i2];
	(*arr)[i2] = temp;
}


int *array_append(int *arr, int arr_size, int value) {
	int i;
	int *out;	

	out = malloc((arr_size + 1)*sizeof(int));
	if (!out)
		return (NULL);
	i = 0;
	while (i < arr_size)
	{
		out[i] = arr[i];
		i++;
	}
	out[i] = value;
	return out;
}

int *array_prepend(int *arr, int arr_size, int value) {
	int i;
	int *out;	

	out = malloc((arr_size + 1)*sizeof(int));
	if (!out)
		return (NULL);
	out[0] = value;
	i = 0;
	while (i < arr_size)
	{
		out[i+1] = arr[i];
		i++;
	}
	return out;
}

int array_rm_index(int *arr, int index)
{
	int i;
	int *out;	
	
	out = malloc((arr_size - 1)*sizeof(int));
	if (!out)
		return (NULL);
	i = 0;
	while (i < arr_size-1)
	{
		out[i] = arr[i+(i>index)];
		i++;
	}
	return out;
}

//-------------------ULTRABASIC STACK MANIP FUNCS
void stack_append(t_stack *stack, int value)
{
	stack->content = array_append(stack->content, stack->current_size, value);
	stack->current_size++;	
}

void stack_prepend(t_stack *stack, int value)
{
	stack->content = array_prepend(stack->content, stack->current_size, value);
	stack->current_size++;	
}

void stack_rm_index(t_stack *stack, int index)
{
	
}

//void stack_swap_indexes(t_stack main, t_stack stache, i1, i2)
//{	
//}

//-------------------BASIC STACK MANIP FUNCS
void s(t_stack stack) //ok!
{
	if (stack.current_size >= 2)
		array_swap_indexes(&(stack.content), 0, 1);
}

void p(t_stack from, t_stack to)
{
	if (from.current_size != 0) {
		stack_prepend(&(to), from->content[0]);
		stack_rm_index(&(to), 0); //TODO
	}
}


//------------------------------ Tests e simili


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

	a_size = 5;
	stack_init(&(a), a_size, 1, 10, a_size*2);
	if (!a.content)
		return 0;

	b.content = NULL;
	b.current_size = 0;
	
	stack_print(a);
	printf("\n");
	stack_prepend(&(a), 892183918);
	stack_append(&(a), 3213213);
	//a.content = array_append(a.content, a.current_size, 412414);
	stack_print(a);
}
