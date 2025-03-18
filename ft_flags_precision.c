/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:36:48 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/22 09:23:11 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags_precision(int pos, const char *str, t_flags *flags)
{
	int	i;
	int	boolean;

	boolean = -1;
	i = pos + 1;
	while (str[i] == '.')
		i++;
	flags->precision = 0;
	while (ft_isdigit(str[i]))
	{
		flags->precision = (flags->precision * 10) + (str[i] - '0');
		i++;
		boolean = 1;
	}
	if (boolean == 1)
		i--;
	return (i);
}
