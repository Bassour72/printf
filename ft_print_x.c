/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 04:05:17 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/24 18:04:24 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(char *nbstr, int n, int is_upper, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.boolean == -1 && flags.hash == 1 && n != 0)
		count += ft_print_hex_prefix(is_upper);
	if (flags.precision >= 0)
		count += ft_paddingsporze(flags.precision - 1, ft_strlen(nbstr) - 1, 1);
	count += ft_print_string_a(nbstr);
	return (count);
}
