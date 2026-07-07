#include "push_swap.h"

void	r_realign(t_stack *stackpt)
{
	r(stackpt, -stackpt->offset);
}

int r_goto_index(t_stack *stackpt, int index, int hmode)
{
    int steps;

	steps = stackpt->current_size - index;
	if (index < stackpt->current_size / 2)
    	steps = -index;
	if (hmode == 1)
	{
		if (steps < 0)
			steps *= -1;
		return steps;
	}
	r(stackpt, steps); 
	return 1;
}
