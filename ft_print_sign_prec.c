/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sign_prec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 03:12:02 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/17 22:13:31 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hnadle_negative(t_flags *flags)
{
	int	count;

	count = 0;
	count += ft_putchar('-');
	if (flags->space == 0)
		flags->width--;
	if (flags->zero == 1 && flags->plus == 1)
		flags->width++;
	return (count);
}

int	ft_print_sign_prec(int n, t_flags *flags)
{
	int	count;

	count = 0;
	if (n < 0 && flags->precision == -1)
		count += ft_hnadle_negative(flags);
	else if (flags->plus == 1 && n >= 0 && flags->precision == -1)
	{
		flags->plus = 0;
		if (flags->zero == 1)
			flags->width--;
		count += ft_putchar('+');
	}
	else if (flags->space == 1)
	{
		if (flags->zero == 1 && n < 0)
			return (count);
		count += ft_putchar(' ');
		if (n < 0 || flags->precision >= 0)
			flags->width--;
	}
	return (count);
}
