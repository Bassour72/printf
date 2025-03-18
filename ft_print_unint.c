/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 04:21:19 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/02 17:58:47 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unint(char *nbstr, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
		count += ft_print_u(nbstr, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbstr))
		flags.precision = ft_strlen(nbstr);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_paddingsporze(flags.width, 0, 0);
	}
	else
		count += ft_paddingsporze(flags.width, ft_strlen(nbstr), flags.zero);
	if (flags.left == 0)
		count += ft_print_u(nbstr, flags);
	return (count);
}
