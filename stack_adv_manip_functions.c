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