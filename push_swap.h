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
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STRATEGIES_ADAPTIVE_CLI 0
#define STRATEGIES_SIMPLE 1
#define STRATEGIES_MEDIUM 2
#define STRATEGIES_COMPLEX 3
#define STRATEGIES_ADAPTIVE 4

typedef struct s_cli_params
{
	int		strategy;
	int		benchmode;
}			t_cli_params;

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

void		program_and_mainstack_init(char **av, int ac,
				t_cli_params *CLI_paramspt, t_stack *stack_apt);
int			input_get_strategy(char **av, int bench_flag_found);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);

int			char_to_number(const char c);
int			char_is_space(char c);

int			string_is_number(const char *str);
int			string_equals(const char *s1, const char *s2);
int			string_has_space(const char *s);

void		bench_init(t_bench *benchpt, float disorder, int CLI_strategy);
void		bench_print(t_bench bench);

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
int			*array_duplicate(int *arr, int size);
int			**array_get_rcombos(int *arr, int size, int iterations);
void		array_shuffle(int *arr, int size, int seed);
int			array_is_sorted(int *array, int array_size);

void		minmax(t_stack *a, t_stack *b);
void		minmax_do1step(t_stack *stack_apt, t_stack *stack_bpt);

int			calculate_bucket_range_gap(t_stack *stackpt, int nbuckets);
void		fill_the_buckets(t_stack *stackpt, int brg, t_stack *buckets,
				int nbuckets);
t_stack		*bucketsort_init(t_stack *stackpt, t_stack *bstackpt);
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

int			ft_printf(const char *str, ...);
int			ft_printf_dispatch(va_list var, char c);
int			print_char(int c);
int			print_string(char *str);
int			print_uint(unsigned int n);
int			print_dec(int n);
int			print_hex(unsigned long n, int upper);
int			print_ptr(void *ptr);

char		*ft_substr(char const *s, unsigned int start, size_t len);

int			string_has_space(const char *s);

char		*ft_strdup(const char *s);