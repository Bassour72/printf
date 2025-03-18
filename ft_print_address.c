/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:50:40 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/24 20:28:42 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_precision(t_flags *flags, unsigned long int n)
{
	flags->zero = 0;
	if (n == 0 && flags->width > flags->precision)
	{
		flags->width -= (flags->precision);
		flags->width++;
	}
	if (flags->width < flags->precision && n != 0)
	{
		flags->width = (flags->width - flags->precision) + 1;
		flags->width -= 2;
	}
}

static void	ft_print_adr(unsigned long int n)
{
	if (n >= 16)
	{
		ft_print_adr(n / 16);
		ft_print_adr(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else if (n >= 10)
			ft_putchar((n - 10) + 'a');
	}
}

static int	ft_print_a(unsigned long int n, t_flags flags)
{
	int	count;

	count = 0;
	if (n == 0 && flags.boolean == -1)
	{
		count += ft_print_string_a("0x0");
		if (flags.precision > 0)
			count += ft_paddingsporze(flags.precision, ft_ptr_len(n), 1);
		return (count);
	}
	if (flags.boolean == -1)
		count += ft_print_string_a("0x");
	if (flags.precision > 0)
		count += ft_paddingsporze(flags.precision, ft_ptr_len(n), 1);
	ft_print_adr(n);
	count += ft_ptr_len(n);
	return (count);
}

int	ft_print_address(unsigned long int n, t_flags flags)
{
	int	count;

	count = 0;
	if (n == 0)
		flags.width -= ft_strlen("0x0") - 1;
	else
		flags.width -= 2;
	if (flags.left == 1)
		count += ft_print_a(n, flags);
	if (flags.precision > 0)
		ft_handle_precision(&flags, n);
	if (flags.zero == 1 && flags.width > 0)
	{
		count += ft_print_string_a("0x");
		flags.boolean = 1;
	}
	count += ft_paddingsporze(flags.width, ft_ptr_len(n), flags.zero);
	if (flags.left == 0)
		count += ft_print_a(n, flags);
	return (count);
}
