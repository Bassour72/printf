/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:14:15 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/23 23:09:49 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	if (write(1, "", 0) == -1)
		return (-1);
	count = 0;
	va_start(args, format);
	count += ft_parse(format, args);
	va_end(args);
	return (count);
}
