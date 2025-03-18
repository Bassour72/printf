/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:51:35 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/24 18:04:24 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_i(char *nbstr, int n, t_flags flags)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (flags.zero == 0 || flags.precision >= 0)
			count += ft_putchar('-');
	}
	else if (flags.plus == 1 && n >= 0)
		count += ft_putchar('+');
	else if (flags.space == 1 && flags.zero == 0)
		count += ft_putchar(' ');
	if (flags.precision >= 0)
		count += ft_paddingsporze(flags.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	count += ft_print_string_a(nbstr);
	return (count);
}
