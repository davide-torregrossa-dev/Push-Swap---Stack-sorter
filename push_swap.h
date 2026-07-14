/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:26:40 by egarlasc          #+#    #+#             */
/*   Updated: 2026/07/06 16:23:06 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STRATEGIES_ADAPTIVE_CLI 0
#define STRATEGIES_SIMPLE 1
#define STRATEGIES_MEDIUM 2
#define STRATEGIES_COMPLEX 3
#define STRATEGIES_ADAPTIVE 4

typedef struct s_program
{
	int		strategy;
	int		benchmode;
}			t_program;

typedef struct s_stack
{
	int		*content;
	int		current_size;
	int		offset;
	char	name;
}			t_stack;

typedef struct s_bucket
{
	int		*content;
	int		current_size;
	int		maxr;
	int		minr;
}			t_bucket;

typedef struct s_combos
{
	int		**result;
	int		current_row;
	int		size;
	int		max_iterations;
}			t_combos;

void		fail(void);

void		program_and_stack_init(char **av, int ac, t_program *programpt,
				t_stack *stack_apt);
int			input_get_strategy(char **av, int bench_flag_found);
double		calculate_disorder(t_stack *stack_apt);

int			char_to_number(const char c);

int			string_is_number(const char *str);
int			string_equals(const char *s1, const char *s2);

void		s(t_stack *stackpt);
void		p(t_stack *from_stackpt, t_stack *to_stackpt);
void		r(t_stack *stackpt, int times);

void		p_pour(t_stack *stack_frompt, t_stack *stack_topt);
void		r_realign(t_stack *stackpt);
void		r_goto_index(t_stack *stackpt, int index);
int			rcost_goto_index(t_stack *stackpt, int from_index,
				int target_index);

void		stack_init(t_stack *stackpt, char name, int *content, int size);
void		stack_print(t_stack stack);

void		stack_append(t_stack *stackpt, int value);
void		stack_prepend(t_stack *stackpt, int value);
void		stack_rm_index(t_stack *stackpt, int index);
void		stack_rotate(t_stack *stackpt, int dir);

int			array_find_string(char **arr, int size, char *query);
int			array_find_int(int *arr, int size, int query);
int			array_find_max_index(int *arr, int size);
int			array_find_min_index(int *arr, int size);
int			*array_swap_indexes(int *arr, int i1, int i2);
int			*array_append(int *arr, int arr_size, int value);
int			*array_prepend(int *arr, int arr_size, int value);
int			*array_rm_index(int *arr, int arr_size, int index);
int			*array_rotate(int *arr, int arr_size, int dir);
void		array_duplicate(int *arr, int *destarr, int size);
int			**array_get_combos(int *arr, int size, int iterations);
int			**array_get_rcombos(int *arr, int size, int iterations);

void		array_shuffle(int *arr, int size, int seed);

void		minmax_do1step(t_stack *stack_apt, t_stack *stack_bpt);

t_stack		*bucketsort_init(t_stack *stackpt);
void		bucketsort_loop(t_stack *tosortpt, t_stack *second_stackpt,
				t_stack *buckets);

int			ft_abs(int n);
int			ft_sqrt(int n);
int			int_in_range(int n, int min, int max);

void		swap(int *a, int *b);
int			factorialof(int n);

int			*router_get_best_order(t_stack *stackpt, int *stops,
				int stops_size);
int			router_calc_routecost(t_stack *stackpt, int *stops, int stops_size);
