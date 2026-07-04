/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ordinato.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:31:05 by egarlasc          #+#    #+#             */
/*   Updated: 2026/06/30 14:38:37 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	stack_init(t_stack *stackpt, char name, int max_size)
{
	stackpt->name = name;
	stackpt->current_size = 0;
	stackpt->max_size = max_size;
	stackpt->offset = 0;
	if (max_size == 0)
	{
		stackpt->content = NULL;
		return (1);
	}
	stackpt->content = malloc(max_size * sizeof(int));
	if (!stackpt->content)
		return (0);
	return (1);
}

int	fill_stack_a(t_stack *stack_apt, char **elements, int elements_len)
{
	int	i;

	if (!stack_init(stack_apt, 'a', elements_len))
		return (0);
	i = 0;
	while (i < elements_len)
	{
		stack_apt->content[i] = (int)ft_atol(elements[i]);
		i++;
	}
	stack_apt->current_size = elements_len;
	return (1);
}
