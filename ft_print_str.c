/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:33:02 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/24 13:41:34 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_string(const char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
		count += ft_print_str_per(str, flags.precision);
	else
		count += ft_print_str_per(str, ft_strlen(str));
	return (count);
}

int	ft_print_str(const char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.left == 1)
		count += ft_handle_string(str, flags);
	if (flags.precision >= 0)
		count += ft_paddingsporze(flags.width, flags.precision, flags.zero);
	else
		count += ft_paddingsporze(flags.width, ft_strlen(str), flags.zero);
	if (flags.left == 0)
		count += ft_handle_string(str, flags);
	return (count);
}
