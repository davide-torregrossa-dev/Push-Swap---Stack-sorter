/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 16:40:20 by dtorregr          #+#    #+#             */
/*   Updated: 2026/06/13 16:40:21 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_hex(int fd, unsigned long n, int upper)
{
	int		out;
	char	*ref;
	char	c;

	out = 0;
	if (upper)
		ref = "0123456789ABCDEF";
	else
		ref = "0123456789abcdef";
	if (n >= 16)
		out += print_hex(fd, n / 16, upper);
	c = ref[n % 16];
	out += write(fd, &c, 1);
	return (out);
}

int	print_ptr(int fd, void *ptr)
{
	unsigned long	n;
	int				out;

	out = 0;
	if (!ptr)
		return (write(fd, "(nil)", 5));
	n = (unsigned long)ptr;
	out += write(fd, "0x", 2);
	out += print_hex(fd, n, 0);
	return (out);
}
