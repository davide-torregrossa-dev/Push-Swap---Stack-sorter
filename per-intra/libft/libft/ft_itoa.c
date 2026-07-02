/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:09:20 by egarlasc          #+#    #+#             */
/*   Updated: 2026/05/28 12:36:09 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long int n)
{
	int	d;

	d = 1;
	if (n < 0)
		n *= -1;
	n = n / 10;
	while (n)
	{
		n = n / 10;
		d++;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			d;
	char		*s;

	nb = n;
	d = count_digits(nb);
	if (n < 0)
	{
		nb *= -1;
		d++;
	}
	s = malloc(sizeof(char) * (d + 1));
	if (!s)
		return (NULL);
	s[d] = '\0';
	d -= 1;
	while (d >= 0)
	{
		s[d] = nb % 10 + '0';
		nb = nb / 10;
		d--;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
