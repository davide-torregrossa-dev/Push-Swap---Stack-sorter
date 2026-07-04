#include "push_swap.h"

void	s(t_stack *stackpt)
{
	if (stackpt->current_size >= 2)
	{
		printf("s%c\n", stackpt->name);
		stackpt->content = array_swap_indexes(stackpt->content, 0, 1);
	}
}

void	p(t_stack *from_stackpt, t_stack *to_stackpt)
{
	if (from_stackpt->current_size != 0)
	{
		printf("p%c\n", from_stackpt->name);
		stack_prepend(to_stackpt, from_stackpt->content[0]);
		stack_rm_index(from_stackpt, 0);
	}
}

void	r(t_stack *stackpt, int times)
{
	int		dir;
	char	*msg;

	msg = "r%c\n";
	if (times < 0)
		msg = "rr%c\n";
	dir = ((times < 0) * 2) - 1;
	while (times != 0)
	{
		printf(msg, stackpt->name);
		stack_rotate(stackpt, dir);
		times += dir;
	}
}