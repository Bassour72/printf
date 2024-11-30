/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:15:24 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 01:55:34 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_unsigned_space(int len, va_list arg)
{
	int				total_count;
	unsigned int	u;
	int				num_len;

	total_count = 0;
	u = va_arg(arg, unsigned int);
	num_len = ft_numsize(u);
	if (num_len < len)
		len -= num_len;
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	total_count += ft_putunbr(u);
	return (total_count);
}

static int	ft_handle_integer_space(int len, va_list arg)
{
	int	total_count;
	int	i;
	int	num_len;

	total_count = 0;
	i = va_arg(arg, int);
	num_len = ft_countint(i);
	if (num_len < len)
		len -= num_len;
	else
		len = 0;
	if (len == 0 && i >= 0)
		len = 1;
	total_count += ft_paddingspace(len, ' ');
	total_count += ft_putnbr(i);
	return (total_count);
}

static int	ft_handle_hex_space(int len, va_list arg, char format)
{
	int				total_count;
	unsigned long	i;
	int				hex_len;

	total_count = 0;
	i = va_arg(arg, unsigned long);
	hex_len = ft_counthex(i);
	if (hex_len < len)
		len -= hex_len;
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	total_count += ft_puthexnbr(i, format);
	return (total_count);
}

static int	ft_handle_pointer_space(int len, va_list arg)
{
	int				total_count;
	unsigned long	ptr;
	int				hex_len;

	total_count = 0;
	ptr = va_arg(arg, unsigned long);
	hex_len = ft_counthex(ptr) + 2;
	if (hex_len < len)
		len -= hex_len;
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	total_count += write(1, "0x", 2);
	total_count += ft_putaddress(&ptr);
	return (total_count);
}

int	ft_handle_space(const char *format, va_list arg, int *format_len)
{
	int	total_count;
	int	len;

	total_count = 0;
	len = 0;
	*format_len += 1 + ft_isnumber(format++, &len);
	format += ft_countdigits(len);
	if (*format == 'c' || *format == '%')
		return (ft_paddingspace(len - 1, ' ') \
		+ ft_putchar((char)va_arg(arg, int)));
	else if (*format == 's')
		total_count += ft_handle_string_all(len, arg, ' ');
	else if (*format == 'u')
		total_count += ft_handle_unsigned_space(len, arg);
	else if (*format == 'i' || *format == 'd')
		total_count += ft_handle_integer_space(len, arg);
	else if (*format == 'x' || *format == 'X')
		total_count += ft_handle_hex_space(len, arg, *format);
	else if (*format == 'p')
		total_count += ft_handle_pointer_space(len, arg);
	return (total_count);
}
