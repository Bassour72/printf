/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:45:43 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 01:42:14 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		format_len;

	format_len = 0;
	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			len += ft_handle_format(*(format), args, format, &format_len);
			format += format_len;
		}
		else
		{
			format_len = 0;
			write(1, format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
