/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 16:40:08 by dtorregr          #+#    #+#             */
/*   Updated: 2026/06/13 16:40:10 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf_dispatch(va_list var, char c)
{
	if (c == '%')
		return (print_char('%'));
	if (c == 'c')
		return (print_char(va_arg(var, int)));
	if (c == 's')
		return (print_string(va_arg(var, char *)));
	if (c == 'i' || c == 'd')
		return (print_dec(va_arg(var, int)));
	if (c == 'u')
		return (print_uint(va_arg(var, unsigned int)));
	if (c == 'p')
		return (print_ptr(va_arg(var, void *)));
	if (c == 'x')
		return (print_hex(va_arg(var, unsigned int), 0));
	if (c == 'X')
		return (print_hex(va_arg(var, unsigned int), 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += ft_printf_dispatch(args, str[i + 1]);
			i += 2;
		}
		if (!str[i])
			break ;
		if (str[i] == '%')
			continue ;
		write(1, &str[i], 1);
		count++;
		i++;
	}
	va_end(args);
	return (count);
}
