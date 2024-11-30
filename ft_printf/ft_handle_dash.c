/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_dash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:11:23 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 02:18:56 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_unsigned(int len, va_list arg)
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
	total_count += ft_putunbr(u);
	total_count += ft_paddingspace(len, ' ');
	return (total_count);
}

static int	ft_handle_integer(int len, va_list arg)
{
	int	total_count;
	int	i;
	int	num_size;

	total_count = 0;
	i = va_arg(arg, int);
	num_size = ft_countint(i);
	if (num_size <= len)
		len -= num_size;
	else
		len = 0;
	total_count += ft_putnbr(i);
	total_count += ft_paddingspace(len, ' ');
	return (total_count);
}

static int	ft_handle_hex(int len, va_list arg, char format)
{
	int				total_count;
	unsigned int	i;
	int				hex_len;

	total_count = 0;
	i = va_arg(arg, unsigned int);
	hex_len = ft_counthex(i);
	if (hex_len <= len)
		len -= hex_len;
	else
		len = 0;
	total_count += ft_puthexnbr(i, format);
	total_count += ft_paddingspace(len, ' ');
	return (total_count);
}

static int	ft_handle_pointer(int len, va_list arg)
{
	int		total_count;
	void	*ptr;
	int		addr_len;

	total_count = 0;
	ptr = va_arg(arg, void *);
	if (ptr == NULL)
	{
		total_count += ft_putstr("0x0");
		total_count += ft_paddingspace(len - 3, ' ');
		return (total_count);
	}
	addr_len = (ft_counthex((unsigned long)ptr)) + 2;
	if (len >= addr_len)
	{
		total_count += ft_putaddress(ptr);
		total_count += ft_paddingspace(len - addr_len, ' ');
	}
	else
		total_count += ft_putaddress(ptr);
	return (total_count);
}

int	ft_handle_dash(const char *format, va_list arg, int *format_len)
{
	int	total_count;
	int	len;

	total_count = 0;
	*format_len += 1 + ft_isnumber(++format, &len);
	format += ft_countdigits(len);
	if (*format == 'c' || *format == '%')
		return (ft_putchar((char)va_arg(arg, int)) \
		+ ft_paddingspace(len - 1, ' '));
	else if (*format == 's')
		total_count += ft_handle_string(len, arg);
	else if (*format == 'u')
		total_count += ft_handle_unsigned(len, arg);
	else if (*format == 'i' || *format == 'd')
		total_count += ft_handle_integer(len, arg);
	else if (*format == 'x' || *format == 'X')
		total_count += ft_handle_hex(len, arg, *format);
	else if (*format == 'p')
		total_count += ft_handle_pointer(len, arg);
	return (total_count);
}
