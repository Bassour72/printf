/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_plus_sign.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:14:23 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 01:58:20 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_unsigned_ps(int len, va_list arg)
{
	int				total_count;
	unsigned int	u;
	int				num_size;

	total_count = 0;
	u = va_arg(arg, unsigned int);
	num_size = ft_numsize(u);
	if (u >= 0 && num_size < len)
		len -= num_size;
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	total_count += ft_putunbr(u);
	return (total_count);
}

static int	ft_handle_signed_ps(int len, va_list arg)
{
	int	total_count;
	int	d;
	int	num_size;

	total_count = 0;
	d = va_arg(arg, int);
	num_size = ft_countint(d);
	if (num_size < len)
	{
		if (d > 0)
			len -= (num_size + 1);
		else
			len -= num_size;
	}
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	if (d >= 0)
		total_count += ft_putchar('+');
	total_count += ft_putnbr(d);
	return (total_count);
}

static int	ft_handle_hex_ps(int len, va_list arg, char format)
{
	int				total_count;
	unsigned long	i;
	int				hex_size;

	total_count = 0;
	i = va_arg(arg, unsigned long);
	hex_size = ft_counthex(i);
	if (hex_size < len)
		len -= hex_size;
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	total_count += ft_puthexnbr(i, format);
	return (total_count);
}

static int	ft_handle_pointer_ps(int len, va_list arg)
{
	int				total_count;
	unsigned long	i;
	int				hex_size;

	total_count = 0;
	i = va_arg(arg, unsigned long);
	hex_size = ft_counthex(i) + 2;
	if (hex_size < len)
		len -= hex_size;
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	total_count += write(1, "0x", 2);
	total_count += ft_putaddress(&i);
	return (total_count);
}

int	ft_handle_plus_sign(const char *format, va_list arg, int *format_len)
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
		total_count += ft_handle_unsigned_ps(len, arg);
	else if (*format == 'i' || *format == 'd')
		total_count += ft_handle_signed_ps(len, arg);
	else if (*format == 'x' || *format == 'X')
		total_count += ft_handle_hex_ps(len, arg, *format);
	else if (*format == 'p')
		total_count += ft_handle_pointer_ps(len, arg);
	return (total_count);
}
