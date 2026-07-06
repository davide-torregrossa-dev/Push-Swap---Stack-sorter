#include "push_swap.h"

void	r_realign(t_stack *stackpt)
{
	r(stackpt, -stackpt->offset);
}

void r_goto_index(t_stack *stackpt, int index)
{
	int	dir;
	int query;

	query = stackpt->content[index];
	dir = 1;
	if (index < (stackpt->current_size / 2))
		dir = -1;
	while (stackpt->content[0] != query)
	{
		r(stackpt, dir);
	}
}
