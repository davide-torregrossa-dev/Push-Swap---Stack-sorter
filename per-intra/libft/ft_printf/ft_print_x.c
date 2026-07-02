/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:17:21 by egarlasc          #+#    #+#             */
/*   Updated: 2026/06/04 10:23:57 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_x_digits(long n)
{
	unsigned int	i;

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

int	ft_print_x(unsigned long nbr)
{
	char			*base;
	char			c;
	unsigned long	n;

	n = nbr;
	base = "0123456789abcdef";
	if (n >= 16)
		ft_print_x(n / 16);
	c = base[n % 16];
	write(1, &c, 1);
	return (count_x_digits(nbr));
}
