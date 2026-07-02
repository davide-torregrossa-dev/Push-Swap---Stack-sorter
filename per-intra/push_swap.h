/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:26:40 by egarlasc          #+#    #+#             */
/*   Updated: 2026/06/30 14:32:45 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Eliminami

#define STRATEGIES_ADAPTIVE 0
#define STRATEGIES_SIMPLE 1
#define STRATEGIES_MEDIUM 2
#define STRATEGIES_COMPLEX 3
#define STRATEGIES_ADAPTIVE_CLI 4

typedef struct s_stack
{
	int		*content;
	int		current_size;
	int		max_size;
	int		offset;
	char	name;
}			t_stack;

typedef struct s_program
{
	int	strategy;
	int	benchmode;
}		t_program;

int	char_to_number(const char c);
int	string_is_number(const char *str);
int	string_equals(const char *s1, const char *s2);
int	array_find_string(char **arr, char *query);
char	**flagnames_array_create(void);
int	input_get_strategy(char **av, int bench_flag_found);
void	input_handling(char **av, int ac, t_program *programpt,
		t_stack *stack_apt);











//int			flags_skipper(int ac, char **av);
//int			is_valid_arg(char *str);
//int			check_limits_and_duplicates(char **args, int current_index,
//				long num);
//int			validate_args(char **args);
