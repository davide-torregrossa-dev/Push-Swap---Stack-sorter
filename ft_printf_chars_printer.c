/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 16:39:41 by dtorregr          #+#    #+#             */
/*   Updated: 2026/06/13 16:39:42 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_char(int fd, int c)
{
	write(fd, &c, 1);
	return (1);
}

int	print_string(int fd, char *str)
{
	size_t	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}
