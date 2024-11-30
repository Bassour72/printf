/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:12:12 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 01:51:30 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_integer_zero(int len, va_list arg)
{
	int	total_count;
	int	i;
	int	numlen;

	total_count = 0;
	i = va_arg(arg, int);
	numlen = ft_countdigits(i);
	if (numlen < len)
		len = len - numlen;
	else
		len = 0;
	if (i < 0)
		write(1, "-", 1);
	if (i == 0)
		len--;
	total_count += ft_paddingspace(len, '0');
	total_count += ft_putlnbr(i);
	return (total_count);
}

static int	ft_handle_hex_zero(int len, va_list arg, char format)
{
	int				total_count;
	unsigned long	l;
	int				hex_len;

	total_count = 0;
	l = va_arg(arg, unsigned long);
	hex_len = ft_counthex(l);
	if (hex_len <= len)
		len = len - hex_len;
	else
		len = 0;
	total_count += ft_paddingspace(len, '0');
	total_count += ft_puthexnbr(l, format);
	return (total_count);
}

static int	ft_handle_pointer_zero(int len, va_list arg)
{
	int				total_count;
	unsigned long	i;
	int				count_hex;

	total_count = 0;
	i = va_arg(arg, unsigned long);
	count_hex = ft_counthex(i) - 2;
	if (count_hex <= len)
		len = len - count_hex;
	else
		len = 0;
	total_count += write(1, "0x", 2);
	total_count += ft_paddingspace(len, '0');
	total_count += ft_putaddress(&i);
	return (total_count);
}

static int	ft_handle_unsigned_zero(int len, va_list arg)
{
	int				total_count;
	unsigned int	u;
	int				numlen;

	total_count = 0;
	u = va_arg(arg, unsigned int);
	numlen = ft_numsize(u);
	if (numlen <= len)
		len = len - numlen;
	else
		len = 0;
	total_count += ft_paddingspace(len, '0');
	total_count += ft_putunbr(u);
	return (total_count);
}

int	ft_handle_zero(const char *format, va_list arg, int *format_len)
{
	int	total_count;
	int	len;

	total_count = 0;
	len = 0;
	*format_len += 1 + ft_isnumber(++format, &len);
	format += ft_countdigits(len);
	if (*format == 'c' || *format == '%')
		return (ft_paddingspace(len - 1, ' ') \
		+ ft_putchar((char)va_arg(arg, int)));
	else if (*format == 's')
		total_count += ft_handle_string_all(len, arg, '0');
	else if (*format == 'u')
		total_count += ft_handle_unsigned_zero(len, arg);
	else if (*format == 'i' || *format == 'd')
		total_count += ft_handle_integer_zero(len, arg);
	else if (*format == 'x' || *format == 'X')
		total_count += ft_handle_hex_zero(len, arg, *format);
	else if (*format == 'p')
		total_count += ft_handle_pointer_zero(len, arg);
	return (total_count);
}
