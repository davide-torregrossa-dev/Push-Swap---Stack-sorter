/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:33:55 by egarlasc          #+#    #+#             */
/*   Updated: 2026/07/03 18:04:22 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_program	program;
	t_stack		a;
	input_handling(av, ac, &program, &a);
	stack_print(a);
	printf("%f\n", calculate_disorder(&a));
}














	/*
args = get_args(av, ac, &is_alloc);
if (!args || !validate_args(args))
{
	if (args && is_alloc)
		ft_free_matrix(args);
	return (1);
}
if (!setup_stacks(&a, &b, args))
{
	if (is_alloc)
		ft_free_matrix(args);
	return (1);
}
return (0);


int	setup_stacks(t_stack *a, t_stack *b, char **args)
{
	int	size_to_assign;

	size_to_assign = 0;
	while (args[size_to_assign] != NULL)
		size_to_assign++;
	if (!fill_stack_a(a, args, size_to_assign))
		return (0);
	if (!stack_init(b, 'b', size_to_assign))
	{
		free(a->content);
		return (0);
	}
	return (1);
}

int	postflags_args_are_ints(char **av, int ac, int from)
{
	int	i;

	i = from;
	while (i < ac)
	{
		printf("%s", av[i]);
		i++;
	}
	return (1);
}
*/
