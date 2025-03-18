/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 04:17:50 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/24 12:18:41 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n, t_flags flags)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (flags.precision == 0 && n == 0)
	{
		count += ft_paddingsporze(flags.width, 0, 0);
		return (count);
	}
	nbstr = ft_utoa(n);
	if (!nbstr)
		return (0);
	count += ft_print_unint(nbstr, flags);
	free(nbstr);
	return (count);
}
