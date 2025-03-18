/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:49:57 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/19 00:13:43 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char specifier, t_flags flags)
{
	char	*nbstr;
	int		count;
	int		is_upper;

	count = 0;
	is_upper = 0;
	if (specifier == 'X')
		is_upper = 1;
	if (flags.precision == 0 && n == 0)
	{
		count += ft_paddingsporze(flags.width, 0, 0);
		return (count);
	}
	nbstr = ft_xtoa(n, is_upper);
	if (!nbstr)
		return (0);
	count += ft_print_hexadecmal(nbstr, n, is_upper, flags);
	free(nbstr);
	return (count);
}
