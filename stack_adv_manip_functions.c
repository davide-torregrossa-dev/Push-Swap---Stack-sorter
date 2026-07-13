#include "push_swap.h"

void	r_realign(t_stack *stackpt)
{
	r(stackpt, -stackpt->offset);
}

void r_goto_index(t_stack *stackpt, int index)
{
    int steps;


    
    steps = stackpt->current_size - index;
	if (index < stackpt->current_size / 2)
    	steps = -index;
	r(stackpt, steps); 
}

int rcost_goto_index(t_stack *stackpt, int from_index, int target_index)
{
    int size;
    int virtual_index;
    int steps;

    size = stackpt->current_size;
    virtual_index = target_index - from_index;
    if (virtual_index < 0)
        virtual_index += size;
    steps = size - virtual_index;
    if (virtual_index < size / 2)
        steps = -virtual_index;
    return (ft_abs(steps));
}

void p_pour(t_stack *stack_frompt, t_stack *stack_topt) 
{
	while (stack_frompt -> current_size != 0)
		p(stack_frompt, stack_topt);
}




 




int router_calc_routecost(t_stack *stackpt, int *stops, int stops_size)
{
    int cost;
    int i;
    int *indexes;

    indexes = malloc(sizeof(int) * stops_size);
    if (!indexes)
        return (-1);
    i = 0;
    while(i < stops_size)
    {
        indexes[i] = array_find_int(stackpt->content, stackpt->current_size, stops[i]);
        i++;
    }
    cost = 0;
    cost += rcost_goto_index(stackpt, 0, indexes[0]);
    i = 1;
    while (i < stops_size-2)
    {
        cost += rcost_goto_index(stackpt, indexes[i], indexes[i+1]);
        i++;
    }
    
    free(indexes);
    return cost;
}

int *router_get_best_order(t_stack *stackpt, int *stops, int stops_size)
{
    int combos_amt;
    int **combos;
    int best_is_at_index;
    int i;
    int *out;

    best_is_at_index = 0;
    printf("%d-----------------------------------\n\n\n", stops_size);
    combos = array_get_all_combos(stops, stops_size);
    combos_amt = factorialof(stops_size);
    i = 0;
    while (i < combos_amt)
    {
        printf("i = %d--------------------%d\n\n\n", i, stops_size);
        if (router_calc_routecost(stackpt, combos[i], stops_size) < 
            router_calc_routecost(stackpt, combos[best_is_at_index], stops_size))
            best_is_at_index = i;
        
        if (i > 8000)
            break;
        i++;
    }
    
    out = malloc(sizeof(int) * stops_size);
    if (!out)
    {
        i = 0;
        while (i < combos_amt) {
            free(combos[i]);
            i++;
        }
        free(combos);
        return NULL;
    }

    array_duplicate(combos[best_is_at_index], out, stops_size);

    i = 0;
    while (i < combos_amt) {
        free(combos[i]);
        i++;
    }
    free(combos);
    
    return out;
}

