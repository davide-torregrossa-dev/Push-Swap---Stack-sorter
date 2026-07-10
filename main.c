/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:33:55 by egarlasc          #+#    #+#             */
/*   Updated: 2026/07/07 16:32:36 by egarlasc         ###   ########.fr       */
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
	//p_pour(&a, &b);
	bucketsort_init(&a);
	bucketsort_loop(&a, &b, bucketsort_init(&a));
	
	//while (b.current_size != 0)
	//	minmax_do1step(&b, &a);
	//r_realign(&a);
//	stack_print(a);
}
