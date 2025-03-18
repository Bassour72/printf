/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:59:56 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/18 23:54:39 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handlecase(t_flags *flags, int n, char *nbstr)
{
	if (n < 0 && flags->left == 0)
	{
		flags->width -= 1;
		if (((size_t)flags->precision <= ft_strlen(nbstr) || \
		(size_t)flags->precision > ft_strlen(nbstr)) && flags->zero == 0)
			flags->width += 1;
	}
	if ((flags->space == 1 || flags->plus == 1) && flags->zero == 0)
		flags->width--;
	if (flags->plus == 1 && flags->zero == 1 && n >= 0)
		flags->width--;
}

int	ft_print_integer(char *nbstr, int n, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero == 1)
		count += ft_print_sign_prec(n, &flags);
	if (flags.left == 1)
		count += ft_print_i(nbstr, n, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbstr))
		flags.precision = ft_strlen(nbstr);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		ft_handlecase(&flags, n, nbstr);
		count += ft_paddingsporze(flags.width, 0, 0);
	}
	else
		count += ft_paddingsporze(flags.width - flags.plus - flags.space, \
				ft_strlen(nbstr), flags.zero);
	if (flags.left == 0)
		count += ft_print_i(nbstr, n, flags);
	return (count);
}
