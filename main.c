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







	

	//in caso di bucketsort
		bucketsort_loop(&a, &b, bucketsort_init(&a));
		stack_print(a);

	/*
		//in caso di simple
		p_pour(&a, &b);
		while (b.current_size != 0)
			minmax_do1step(&b, &a);
		r_realign(&a);
		stack_print(a);
	*/

		/*
	
	
	
		//test combo
	int *test = malloc(5 * sizeof(int));
	
	int	i;
	int	j;
	int	total;
	test[0] = 10;
	test[1] = 20;
	test[2] = 30;
	test[3] = 40;
	test[4] = 50;
	int **out = array_get_all_combos(test, 5);
	total = factorialof(5);
	i = 0;


	while (i < total)
	{
		j = 0;
		while (j < 5)
		{
			printf("%d ", out[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
*/
}
