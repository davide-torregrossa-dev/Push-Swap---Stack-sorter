/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:33:55 by egarlasc          #+#    #+#             */
/*   Updated: 2026/07/06 16:27:27 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//integrare un counter per le mosse

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_program	program;
	t_stack		a;
	t_stack		b;
	program_and_stack_init(av, ac, &program, &a);
	stack_init(&b, 'b', NULL, 0);
	
	
	//stack_print(a);
	int i = 0;
	while (a.current_size != 0)
	{
		minmax_do1step(&a, &b);
		i++;
	}
	//stack_print(b);
	//printf("%f\n", calculate_disorder(&a));
	//stack_print(a);
}