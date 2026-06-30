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

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <time.h> //Eliminami

typedef struct s_stack
{
	int		*content;
	int		current_size;
	int		max_size;
	int		offset;
	char	name;
}	t_stack;

int	flags_skipper(int ac, char **av);
int	is_valid_arg(char *str);
int check_limits_and_duplicates(char **args, int current_index, long num);
int validate_args(char **args);
