/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarlasc <egarlasc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:03:54 by egarlasc          #+#    #+#             */
/*   Updated: 2026/06/04 10:36:32 by egarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(va_list var, char f)
{
	int	count;

	count = 0;
	if (f == '%')
		count += ft_print_c('%');
	else if (f == 'i' || f == 'd')
		count += ft_print_d(va_arg(var, int));
	else if (f == 'c')
		count += ft_print_c(va_arg(var, int));
	else if (f == 'u')
		count += ft_print_u(va_arg(var, unsigned int));
	else if (f == 'p')
		count += ft_print_ptr(va_arg(var, void *));
	else if (f == 's')
		count += ft_print_s(va_arg(var, char *));
	else if (f == 'x')
		count += ft_print_x(va_arg(var, unsigned int));
	else if (f == 'X')
		count += ft_print_x_up(va_arg(var, unsigned int));
	return (count);
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
			i++;
			count += ft_formats(args, str[i]);
			i++;
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
