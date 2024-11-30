/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hash_sign.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:13:39 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 02:01:55 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_stringsh(int len, char *str)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (strlen < len)
		len -= strlen;
	else
		len = 0;
	return (ft_paddingspace(len, ' ') + ft_putstr(str));
}

static int	ft_handle_number(int len, int num, char format)
{
	int	total_count;
	int	numlen;

	total_count = 0;
	numlen = 0;
	if (format == 'u')
		numlen = ft_countdigits_unsigned((unsigned int)num);
	if (format == 'i' || format == 'd')
		numlen = ft_countdigits(num);
	if (numlen < len)
		len -= numlen;
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	if (format == 'u')
		total_count += ft_putunbr((unsigned int)num);
	else
		total_count += ft_putnbr(num);
	return (total_count);
}

static int	ft_handle_hex(int len, unsigned long i, char format)
{
	int	total_count;
	int	count_hex;

	total_count = 0;
	if (i != 0)
		count_hex = ft_counthex(i) + 2;
	else
		count_hex = ft_counthex(i);
	if (count_hex < len)
		len -= count_hex;
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	if (i != 0)
	{
		if (format == 'x')
			total_count += write(1, "0x", 2);
		else if (format == 'X')
			total_count += write(1, "0X", 2);
	}
	if (i == 0)
		total_count += write(1, "0", 1);
	else
		total_count += ft_puthexnbr(i, format);
	return (total_count);
}

static int	ft_handle_pointer(int len, void *ptr)
{
	int				total_count;
	unsigned long	addr;
	int				count_hex;

	total_count = 0;
	addr = (unsigned long)ptr;
	count_hex = ft_counthex(addr) - 2;
	if (count_hex < len)
		len -= count_hex;
	else
		len = 0;
	total_count += ft_paddingspace(len, ' ');
	total_count += ft_putaddress(ptr);
	return (total_count);
}

int	ft_handle_hash_sign(const char *format, va_list arg, int *format_len)
{
	int	tcount;
	int	len;

	tcount = 0;
	len = 0;
	*format_len += 1 + ft_isnumber(format++, &len);
	format += ft_countdigits(len);
	if (*format == 'c' || *format == '%')
		return (ft_paddingspace(len - 1, ' ') \
		+ ft_putchar((char)va_arg(arg, int)));
	if (*format == 's')
		return (tcount += ft_handle_stringsh(len, va_arg(arg, char *)));
	if (*format == 'u' || *format == 'i' || *format == 'd')
		return (tcount += ft_handle_number(len, va_arg(arg, int), *format));
	if (*format == 'x' || *format == 'X')
		return (tcount += \
		ft_handle_hex(len, va_arg(arg, unsigned long), *format));
	if (*format == 'p')
		return (tcount += ft_handle_pointer(len, va_arg(arg, void *)));
	return (0);
}
