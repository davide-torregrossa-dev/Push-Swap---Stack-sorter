#include "push_swap.h"

void	stack_rotate(t_stack *stackpt, int dir)
{
	stackpt->content = array_rotate(stackpt->content, stackpt->current_size,
			dir);
	stackpt->offset -= dir;
}

