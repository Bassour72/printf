/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:16:51 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 02:10:48 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_unsigned(int len, va_list arg)
{
	int				total_count;
	unsigned int	u;
	int				strlen;

	total_count = 0;
	u = va_arg(arg, unsigned int);
	strlen = ft_numsize(u);
	if (strlen <= len)
		len = len - strlen;
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	total_count += ft_putunbr(u);
	return (total_count);
}

static int	ft_handle_integer(int len, va_list arg)
{
	int	total_count;
	int	i;
	int	strlen;

	total_count = 0;
	i = va_arg(arg, int);
	strlen = ft_numsize(i);
	if (strlen <= len)
	{
		if (i < 0)
			len = len - (strlen - 1);
		else
			len = len - strlen;
	}
	else
		len = 0;
	if (i < 0)
		total_count += write(1, "-", 1);
	total_count += ft_paddingspace(len, ' ');
	total_count += ft_putnbr(i);
	return (total_count);
}

static int	ft_handle_hexadecimal(int len, va_list arg, char format)
{
	int				total_count;
	unsigned long	i;
	int				hex_len;

	total_count = 0;
	i = va_arg(arg, unsigned long);
	hex_len = ft_counthex(i);
	if (hex_len <= len)
		len = len - hex_len;
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	total_count += ft_puthexnbr(i, format);
	return (total_count);
}

static int	ft_handle_pointer(int len, va_list arg)
{
	int		total_count;
	void	*v;
	int		count_hex;
	int		addr_len;

	total_count = 0;
	v = va_arg(arg, void *);
	count_hex = ft_counthex((unsigned long)v);
	if (v == NULL)
	{
		total_count += ft_putstr("0x0");
		total_count += ft_paddingspace(len - 3, ' ');
		return (total_count);
	}
	addr_len = count_hex + 2;
	if (len > addr_len)
		len -= addr_len;
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	total_count += ft_putaddress(v);
	return (total_count);
}

int	ft_handle_digits(const char *format, va_list arg, int *format_len)
{
	int	total_count;
	int	len;

	total_count = 0;
	*format_len += ft_isnumber(format, &len);
	format += ft_countdigits(len);
	if (*format == 'c' || *format == '%')
		return (ft_paddingspace(len - 1, ' ') \
		+ ft_putchar((char)va_arg(arg, int)));
	else if (*format == 's')
		total_count += ft_handle_string_all(len, arg, ' ');
	else if (*format == 'u')
		total_count += ft_handle_unsigned(len, arg);
	else if (*format == 'i' || *format == 'd')
		total_count += ft_handle_integer(len, arg);
	else if (*format == 'x' || *format == 'X')
		total_count += ft_handle_hexadecimal(len, arg, *format);
	else if (*format == 'p')
		total_count += ft_handle_pointer(len, arg);
	return (total_count);
}
