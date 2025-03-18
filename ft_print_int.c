/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:51:55 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/21 15:41:00 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handleplus(t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->left == 1)
	{
		if (flags->plus == 1)
			count += ft_putchar('+');
	}
	if (flags->plus == 1)
		flags->width--;
	count += ft_paddingsporze(flags->width, 0, 0);
	if (flags->left == 0 && flags->plus == 1)
	{
		if (flags->plus == 1)
			count += ft_putchar('+');
	}
	return (count);
}

int	ft_print_int(int n, t_flags flags)
{
	char	*nbstr;
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		if (flags.zero == 0 && flags.space == 0 && flags.plus == 0)
			flags.width--;
	}
	if (flags.precision == 0 && n == 0)
	{
		count += ft_handleplus(&flags);
		return (count);
	}
	nbstr = ft_itoa(nb);
	if (!nbstr)
		return (0);
	count += ft_print_integer(nbstr, n, flags);
	free(nbstr);
	return (count);
}
