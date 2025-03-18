/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecmal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 03:57:38 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/18 23:51:04 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_zero(char *nbstr, t_flags flags)
{
	int	count;

	count = 0;
	if (nbstr[0] == '0')
		count += ft_paddingsporze(flags.width, ft_strlen(nbstr), flags.zero);
	else
	{
		count += ft_paddingsporze(flags.width, \
		ft_strlen(nbstr) + (flags.hash * 2), flags.zero);
	}
	return (count);
}

static int	ft_hnadle_left_prefix(int is_upper, t_flags *flags)
{
	int	count;

	count = 0;
	count += ft_print_hex_prefix(is_upper);
	flags->boolean = 1;
	return (count);
}

int	ft_print_hexadecmal(char *nbstr, int n, int is_upper, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero == 1 && flags.hash == 1 && n != 0 && \
	flags.precision == -1 && flags.width > 0)
		count += ft_hnadle_left_prefix(is_upper, &flags);
	if (flags.left == 1)
		count += ft_print_x(nbstr, n, is_upper, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbstr))
		flags.precision = ft_strlen(nbstr);
	if ((size_t)flags.precision > 0 && flags.hash == 1 \
	&& flags.precision != -1 && n != 0)
		flags.width -= 2;
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_paddingsporze(flags.width, 0, 0);
	}
	else
		count += ft_handle_zero(nbstr, flags);
	if (flags.left == 0)
		count += ft_print_x(nbstr, n, is_upper, flags);
	return (count);
}
