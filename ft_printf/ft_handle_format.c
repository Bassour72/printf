/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:19:29 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 02:06:25 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_basic_specifiers(char specifier, va_list args)
{
	if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (specifier == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	if (specifier == 'p')
		return (ft_putaddress(va_arg(args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (specifier == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (specifier == 'x' || specifier == 'X')
		return (ft_puthexnbr(va_arg(args, unsigned int), specifier));
	if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	ft_handle_s(char spec, va_list args, const char *format, int *len)
{
	if (spec == '-')
		return (ft_handle_dash(format, args, len));
	if (spec == '0')
		return (ft_handle_zero(format, args, len));
	if (spec == '.')
		return (ft_handle_decimal_point(format, args, len));
	if (spec == '+')
		return (ft_handle_plus_sign(format, args, len));
	if (spec == '#')
		return (ft_handle_hash_sign(format, args, len));
	if (spec == ' ')
		return (ft_handle_space(format, args, len));
	if (ft_isdigit(spec))
		return (ft_handle_digits(format, args, len));
	return (0);
}

int	ft_handle_format(char spec, va_list args, const char *format, int *len)
{
	int	total_count;

	total_count = 0;
	total_count += ft_handle_basic_specifiers(spec, args);
	if (total_count == 0)
		total_count += ft_handle_s(spec, args, format, len);
	return (total_count);
}
