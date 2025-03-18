/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:21:43 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/24 11:26:54 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_flags(int i, const char *str, t_flags *flags)
{
	while (str[++i] && ft_isutils_format_flags(str[i]))
	{
		if (str[i] == '-')
			*flags = ft_flags_left(*flags);
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '0' && flags->left == 0 && flags->width == 0)
			flags->zero = 1;
		if (ft_isdigit(str[i]))
			i = ft_flags_width(flags, str, i);
		if (str[i] == '.')
			i = ft_flags_precision(i, str, flags);
		if (ft_isspecifiertype(str[i]))
		{
			flags->specifier = str[i];
			break ;
		}
	}
	return (i);
}
