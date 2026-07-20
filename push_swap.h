/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:26:06 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/19 17:26:07 by dtorregr         ###   ########.fr       */
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

typedef struct s_CLI_params
{
	int		strategy;
	int		benchmode;
}			t_CLI_params;

typedef struct s_bench
{
	int		is_active;
	int		pa;
	int		pb;
	int		sa;
	int		sb;
	int		ss;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
	int		strategy;
	int		strategy_is_from_adaptive;
	float	disorder;
}			t_bench;

typedef struct s_stack
{
	int		*content;
	int		current_size;
	int		offset;
	char	name;
	t_bench	*bench;
}			t_stack;

typedef struct s_bucket
{
	int		*content;
	int		current_size;
	int		maxr;
	int		minr;
}			t_bucket;

void		fail(void);

void		program_and_mainstack_init(char **av, int ac, t_CLI_params *CLI_paramspt,
				t_stack *stack_apt);
int			input_get_strategy(char **av, int bench_flag_found);

int			char_to_number(const char c);

int			string_is_number(const char *str);
int			string_equals(const char *s1, const char *s2);

void		s(t_stack *stackpt);
void		p(t_stack *from_stackpt, t_stack *to_stackpt);
void		r(t_stack *stackpt, int times);

void		p_pour(t_stack *stack_frompt, t_stack *stack_topt);
void		r_realign(t_stack *stackpt);
void		r_goto_index(t_stack *stackpt, int index);

int			stack_init(t_stack *stackpt, char name, int *content, int size);
void		stack_print(t_stack stack);

float		stack_calc_disorder(t_stack *stack_apt);
int			stack_append(t_stack *stackpt, int value);
int			stack_prepend(t_stack *stackpt, int value);
int			stack_rm_index(t_stack *stackpt, int index);
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
int			**array_get_rcombos(int *arr, int size, int iterations);
void		array_shuffle(int *arr, int size, int seed);

void		minmax(t_stack *a, t_stack *b);
void		minmax_do1step(t_stack *stack_apt, t_stack *stack_bpt);

t_stack		*bucketsort_init(t_stack *stackpt);
void		bucketsort(t_stack *tosortpt, t_stack *second_stackpt,
				t_stack *buckets);

void		radix_sort(t_stack *tosortpt, t_stack *second_stackpt);

float		float_truncate(float n, int decs);
int			ft_abs(int n);
int			ft_sqrt(int n);
int			int_in_range(int n, int min, int max);
int			factorialof(int n);

int			*router_get_best_order(t_stack *stackpt, int *stops,
				int stops_size);

/*
int	router_calc_lanecost(t_stack *stackpt, int from_index,
				int target_index);


int			router_calc_routecost(t_stack *stackpt, int *stops, int stops_size);
*/
