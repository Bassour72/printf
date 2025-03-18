/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:48:23 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/21 12:33:48 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char c, t_flags flags, va_list args)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_print_char('%', flags);
	else if (c == 'c')
		count += ft_print_char((char)va_arg(args, int), flags);
	else if (c == 's')
		count += ft_print_str(va_arg(args, const char *), flags);
	else if (c == 'd' || c == 'i')
		count += ft_print_int(va_arg(args, int), flags);
	else if (c == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int), flags);
	else if (c == 'x' || c == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), c, flags);
	else if (c == 'p')
		count += ft_print_address((unsigned long int)va_arg(args, \
		void *), flags);
	return (count);
}
