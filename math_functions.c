/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:48:20 by dtorregr          #+#    #+#             */
/*   Updated: 2026/07/14 13:48:21 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	int_in_range(int n, int min, int max)
{
	if (n >= min && n <= max)
		return (1);
	return (0);
}

int	ft_sqrt(int n)
{
	long	x;
	long	y;

	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	x = n;
	y = (x + 1) / 2;
	while (y < x)
	{
		x = y;
		y = (x + n / x) / 2;
	}
	return ((int)x);
}

int	factorialof(int n)
{
	int	f;
	int	i;

	f = 1;
	i = 1;
	while (i <= n)
	{
		f *= i;
		i++;
	}
	return (f);
}
