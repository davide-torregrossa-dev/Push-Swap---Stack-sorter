/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:54:50 by egarlasc          #+#    #+#             */
/*   Updated: 2026/06/04 10:23:18 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_uns_digits(unsigned int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

int	ft_print_u(unsigned int n)
{
	unsigned long	nb;
	char			c;

	nb = n;
	if (nb >= 10)
		ft_print_u(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	return (count_uns_digits(n));
}
