/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_decimal_point.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:12:59 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 02:26:11 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_unsigned_dp(int len, va_list arg)
{
	int				total_count;
	unsigned int	u;
	int				num_size;

	total_count = 0;
	u = va_arg(arg, unsigned int);
	num_size = ft_numsize(u);
	if (num_size <= len)
		len -= num_size;
	else
		len = 0;
	total_count += ft_paddingspace(len, '0');
	total_count += ft_putunbr(u);
	return (total_count);
}

static int	ft_handle_integer_dp(int len, va_list arg)
{
	int	total_count;
	int	i;
	int	num_size;

	total_count = 0;
	i = va_arg(arg, int);
	num_size = ft_countint(i);
	if (num_size <= len)
	{
		if (i < 0)
			len -= (num_size - 1);
		else
			len -= num_size;
	}
	else
		len = 0;
	if (i < 0)
		write(1, "-", 1);
	total_count += ft_paddingspace(len, '0');
	total_count += ft_putllnbr(i);
	return (total_count);
}

static int	ft_handle_hexadecimal_dp(int len, va_list arg, char format)
{
	int				total_count;
	unsigned long	i;
	int				hex_len;

	total_count = 0;
	i = va_arg(arg, unsigned long);
	hex_len = ft_counthex(i);
	if (hex_len <= len)
		len -= hex_len;
	else
		len = 0;
	total_count += ft_paddingspace(len, '0');
	total_count += ft_puthexnbr(i, format);
	return (total_count);
}

static int	ft_handle_pointer_dp(int len, va_list arg)
{
	int				total_count;
	unsigned long	i;
	int				count_hex;

	total_count = 0;
	i = va_arg(arg, unsigned long);
	count_hex = ft_counthex(i) - 4;
	if (count_hex <= len)
		len -= count_hex;
	else
		len = 0;
	total_count += write(1, "0x", 2);
	total_count += ft_paddingspace(len, '0');
	total_count += ft_putaddress(&i);
	return (total_count);
}

int	ft_handle_decimal_point(const char *format, va_list arg, int *format_len)
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
		total_count += ft_handle_string_all(len, arg, ' ');
	else if (*format == 'u')
		total_count += ft_handle_unsigned_dp(len, arg);
	else if (*format == 'i' || *format == 'd')
		total_count += ft_handle_integer_dp(len, arg);
	else if (*format == 'x' || *format == 'X')
		total_count += ft_handle_hexadecimal_dp(len, arg, *format);
	else if (*format == 'p')
		total_count += ft_handle_pointer_dp(len, arg);
	return (total_count);
}
