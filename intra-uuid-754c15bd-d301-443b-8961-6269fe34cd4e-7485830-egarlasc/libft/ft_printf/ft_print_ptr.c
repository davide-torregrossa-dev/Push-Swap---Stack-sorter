/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:58:37 by egarlasc          #+#    #+#             */
/*   Updated: 2026/06/04 10:57:28 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_x_digits(unsigned long n)
{
	unsigned long	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	nb;
	unsigned long	n;

	if (!ptr)
		return (write(1, "(nil)", 5));
	nb = (unsigned long)ptr;
	n = nb;
	write (1, "0x", 2);
	ft_print_x(nb);
	return (count_x_digits(n) + 2);
}
