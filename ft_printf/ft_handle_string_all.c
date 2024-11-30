/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string_all.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:21:59 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 01:53:04 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_string_all(int len, va_list arg, char padd_char)
{
	int		total_count;
	char	*str;
	int		strlen;

	total_count = 0;
	str = va_arg(arg, char *);
	strlen = ft_strlen(str);
	if (strlen <= len)
		len = len - strlen;
	else
		len = 0;
	total_count += ft_paddingspace(len, padd_char);
	total_count += ft_putstr(str);
	return (total_count);
}
