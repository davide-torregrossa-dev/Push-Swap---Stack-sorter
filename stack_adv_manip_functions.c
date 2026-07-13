#include "push_swap.h"

void	r_realign(t_stack *stackpt)
{
	r(stackpt, -stackpt->offset);
}

void r_goto_index(t_stack *stackpt, int index)
{
    int steps;

    if index == 0
        return;
    
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




 




int stack_route_calcolate_cost(t_stack *stackpt, int *indexes, int indexes_size)
{
    int out;
    int i;

    i = 0;
    out = 0;
    out += rcost_goto_index(stackpt, 0, indexes[i]);
    while (i < indexes_size-1)
    {
        out += rcost_goto_index(stackpt, indexes[i], indexes[i+1]);
        i++;
    }
    return out;
}

int *stack_get_bestroute_for_indexes(t_stack *stackpt, int *indexes, int indexes_size)
{
    int combos_amt;
    int **combos;
    int best_is_at_index;
    int i;
    int temp;
    int *result;

    combos = array_get_all_combos(indexes, indexes_size);
    best_is_at_index = 0;
    combos_amt = factorialof(indexes_size);
    
    i = 0;
    while (i < combos_amt)
    {
        // FIX: Passa indexes_size, non combos_amt!
        if (stack_route_calcolate_cost(stackpt, combos[i], indexes_size) < 
            stack_route_calcolate_cost(stackpt, combos[best_is_at_index], indexes_size))
            best_is_at_index = i;
        i++;
    }
    
    // Alloca memoria per il risultato
    result = malloc(sizeof(int) * indexes_size);
    if (!result)
        return NULL;
    
    i = 0;
    while(i < indexes_size) {
        temp = combos[best_is_at_index][i];
        // FIX: Verifica che l'indice sia valido
        if (temp >= 0 && temp < stackpt->current_size)
            result[i] = stackpt->content[temp];
        else
            result[i] = 0; // Fallback se indice non valido
        i++;
    }

    // Libera tutte le combinazioni
    i = 0;
    while (i < combos_amt) {
        free(combos[i]);
        i++;
    }
    free(combos);
    
    return result;
}

