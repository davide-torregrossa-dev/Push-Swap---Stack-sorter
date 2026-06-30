/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:33:55 by egarlasc          #+#    #+#             */
/*   Updated: 2026/06/30 19:49:29 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
*/



int is_same_string(const char *s1, const char *s2)
{
    int i;
    if (s1 == NULL || s2 == NULL)
        return 0;
    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return 1;
    return 0;
}

int stringarray_find_index(char **arr, char *query)
{
    int i;
    if (arr == NULL || query == NULL)
        return 0;
    i = 0;
    while (arr[i] != NULL)
    {
        if (is_same_string(arr[i], query) == 1)
            return i;
        i++;
    }
    return -1;
}

int string_is_number(const char *str)
{
    int i;

    if (str == NULL || str[0] == '\0')
        return 0;
    i = 0;
    if (str[0] == '-' || str[0] == '+')
    {
        i++;
        if (str[i] == '\0')
            return 0;
    }
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

void fail() {
	write(1, "Error\n", 6);
	exit(1);
}

char **flags_init(void)
{
    char **flags;
    flags = (char **)malloc(6 * sizeof(char *));
    if (flags == NULL)
    {
        return NULL;
    }
    flags[0] = "--simple";
    flags[1] = "--medium";
    flags[2] = "--complex";
    flags[3] = "--adaptive";
    flags[4] = "--bench";
    flags[5] = NULL;
    return flags;
}

int	main(int ac, char **av)
{
	char	**flags;

	if (ac == 1)
		fail();
	flags = flags_init();
	if (string_is_number(av[1]))
	{	
		printf("%s", "Il secondo è un numero.");
		//importare da 2 a argc-1, verificando che siano solo numeri e controllando "dietro" che non vi siano duplicati
	}
	else if(stringarray_find_index(flags, av[1]) > 0)
	{
		if (ac != 3)
			fail();
		printf("%s", "Il secondo è una flag.");
		//importare terzo parametro, verificando che siano solo numeri e controllando "dietro" che non vi siano duplicati
	} else
		fail();
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
	*/
