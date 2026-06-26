#include "push_swap.h"

typedef struct s_stack
{
	int *content;
	int current_size;
	int offset;
}	t_stack;


//-------------------ARRAY FUNCS
int *array_swap_indexes(int *arr, int i1, int i2) {
	int	temp;
	
	temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
	return arr;
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
	free(arr);
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
	free(arr);
	return out;
}

int *array_rm_index(int *arr, int arr_size, int index)
{
	int i;
	int *out;
	
	out = malloc((arr_size - 1)*sizeof(int));
	if (!out)
		return (NULL);
	i = 0;
	while (i < arr_size-1)
	{
		out[i] = arr[i+(i>=index)];
		i++;
	}
	free(arr);
	return out;
}

int *array_rotate(int *arr, int arr_size, int dir)
{
	int i;
	int *out;
	int offset;

	if (!arr || arr_size <= 0)
		return NULL;
	if (dir != -1 && dir != 1)
		return NULL;
	out = malloc(arr_size * sizeof(int));
	if (!out)
		return NULL;
	offset = -dir; 
	i = 0;
	while (i < arr_size)
	{
	out[i] = arr[(i + offset + arr_size) % arr_size];
		i++;
	}
	free(arr);
	return out;
}

int *array_rotate_bak(int *arr, int arr_size, int times)
{
	int i;
	int shift;
	int *out;

	if (!arr || arr_size <= 0)
		return NULL;
	shift = times % arr_size;
	if (shift < 0)
		shift += arr_size;
	out = malloc(arr_size * sizeof(int));
	if (!out)
		return (NULL);
	i = 0;
	while (i < arr_size)
	{
		out[i] = arr[(i + shift) % arr_size];
		i++;
	}
	free(arr);
	return out;
}

//-------------------ULTRABASIC STACK MANIP FUNCS
void stack_append(t_stack *stackpt, int value)
{
	stackpt->content = array_append(stackpt->content, stackpt->current_size, value);
	stackpt->current_size++;	
}

void stack_prepend(t_stack *stackpt, int value)
{
	stackpt->content = array_prepend(stackpt->content, stackpt->current_size, value);
	stackpt->current_size++;	
}

void stack_rm_index(t_stack *stackpt, int index)
{
	stackpt->content = array_rm_index(stackpt->content, stackpt->current_size, index);
	stackpt->current_size--;
}

void stack_rotate(t_stack *stackpt, int times)
{
	stackpt->content = array_rotate(stackpt->content, stackpt->current_size, times);
}
//void stack_swap_indexes(t_stack main, t_stack stache, i1, i2)
//{	
//}

//-------------------BASIC STACK MANIP FUNCS
void s(char stackname, t_stack *stackpt) //ok!
{
	if (stackpt->current_size >= 2)
	{
		printf("s%c\n", stackname);
		stackpt->content = array_swap_indexes(stackpt->content, 0, 1);		
	}
}

void p(char stackname, t_stack *from_stackpt, t_stack *to_stackpt)
{
	if (from_stackpt->current_size != 0) {
		printf("p%c\n", stackname);
		stack_prepend(to_stackpt, from_stackpt->content[0]);
		stack_rm_index(from_stackpt, 0);
	}
}

void r(char stackname, t_stack *stackpt, int times)
{
	printf("r%c\n", stackname);
	stack_rotate(stackpt, times);
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
	stack->offset = 0;
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
		stack->content = array_swap_indexes(stack->content, random_int(0, size-1), random_int(0, size-1));
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
	stack_init(&a, a_size, 1, 10, a_size*2);
	if (!a.content)
		return 0;

	b.content = NULL;
	b.current_size = 0;
}
