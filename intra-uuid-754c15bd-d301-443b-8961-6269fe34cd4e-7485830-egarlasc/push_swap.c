#include "push_swap.h"

//stack_swap_indexes è rotta.
//non toccare array_rotate, ora funziona!
//Integrare pivot e safenums (o sorter struct).
//scrivere e integrare RRR!;

typedef struct s_stack
{
	int *content;
	int current_size;
	int	max_size;
	int offset;	//Indica l'orientamento della stack, basato su quante volte è stata chiamata una funzione r* su questa)
	char name;
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
    int temp;

    if (arr == NULL || arr_size <= 1)
        return arr;
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
    return arr;
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

void stack_rotate(t_stack *stackpt, int dir)
{
	stackpt->content = array_rotate(stackpt->content, stackpt->current_size, dir);
	stackpt->offset -= dir;
}

//-------------------BASIC STACK MANIP FUNCS
void s(t_stack *stackpt)
{
	if (stackpt->current_size >= 2)
	{
		printf("s%c\n", stackpt->name);
		stackpt->content = array_swap_indexes(stackpt->content, 0, 1);		
	}
}

void p(t_stack *from_stackpt, t_stack *to_stackpt)
{
	if (from_stackpt->current_size != 0) 
	{
		printf("p%c\n", from_stackpt->name);
		stack_prepend(to_stackpt, from_stackpt->content[0]);
		stack_rm_index(from_stackpt, 0);
	}
}

void r(t_stack *stackpt, int times)
{
	int dir;
	char *msg;

	msg = "r%c\n";
	if (times < 0)
		msg = "rr%c\n";
	dir = ((times < 0)*2)-1;
	while (times != 0) 
	{
		printf(msg, stackpt->name);
		stack_rotate(stackpt, dir);
		times += dir;
	}
}

/*
void rrr(t_stack *stack_apt, t_stack *stack_bpt, int times) {
	int dir;

	dir = ((times < 0)*2)-1;
	while (times != 0) {	
		printf("rrr->");
		r(stack_bpt, times);
		printf("rrr->");
		r(stack_bpt, times);
		times += dir;
	}
}
*/

//-------------------ADV STACK MANIP FUNCS

void stack_swap_indexes(t_stack *mainpt, t_stack *stachept, int i1, int i2)
{
    int temp;
    int r2;

    if (!mainpt || mainpt->current_size < 2 || i1 == i2)
        return;
    if (i1 < 0 || i1 >= mainpt->current_size || i2 < 0 || i2 >= mainpt->current_size)
        return;
    if (i1 > i2)
    {
        temp = i1;
        i1 = i2;
        i2 = temp;
    }
    r(mainpt, i1);
    p(mainpt, stachept);
    r2 = i2 - i1 - 1;
    r(mainpt, r2);
    p(mainpt, stachept);
    s(stachept);
    p(stachept, mainpt);
    r(mainpt, -r2);
    r(mainpt, -i1);
    p(stachept, mainpt);
}

void stack_realign(t_stack *stackpt)
{
	r(stackpt, -stackpt->offset);
}

//------------------------------ Tests e simili

int random_int(int min, int max)
{
	return min + rand() % (max - min + 1);
}

int stack_init(t_stack *stack, char name, int size, int minstep, int maxstep, int shuffles) {
	int i = 0;
	int content = 0;
	
	srand(time(NULL));
	stack->name = name;	
	stack->content = malloc(size * sizeof(int));
	stack->offset = 0;
	if (stack->content == NULL)
		return 0;
	stack->current_size = size;
	if (size==0)
		return 1;

	while (i < size) {
		content += random_int(minstep, maxstep);	
		stack->content[i] = content;
		i++;
	}
	i = 0;
	while (i < shuffles) {
		stack->content = array_swap_indexes(stack->content, random_int(0, size-1), random_int(0, size-1));
		i++;
	}
	return 1;
}

void stack_print(t_stack stack)
{
	int i;
	i = 0;
	printf("------[ %c ]------\n", stack.name-32);
	printf("|curr_size: %d \t|\n", stack.current_size);
	printf("|offset: %d\t|\n", stack.offset);
	printf("-----------------\n");
	while (i < stack.current_size) {
		printf("|%c%d\t%d\t|\n", stack.name-32, i, stack.content[i]);

		i++;
	}
	printf("-----------------\n");

}


//---------------------------------------------------MAIN
int main() {
	t_stack a;
	t_stack b;
	
	if (!stack_init(&a, 'a', 9, 1, 9, 500))
		return 0;
	if (!stack_init(&b, 'b', 0, 1, 10, 500))
		return 0;
	
	stack_print(a);
	printf("\n");
	stack_swap_indexes(&a, &b, 0, 7);
	printf("\n");
	stack_print(a);
}
