/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:29:13 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 01:52:25 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_string(int len, va_list arg)
{
	int		total_count;
	char	*str;
	int		str_len;

	total_count = 0;
	str = va_arg(arg, char *);
	str_len = ft_strlen(str);
	if (str_len <= len)
		len -= str_len;
	else
		len = 0;
	total_count += ft_putstr(str);
	total_count += ft_paddingspace(len, ' ');
	return (total_count);
}
