/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:03:08 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/23 23:09:58 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(const char *str, va_list args)
{
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	while (str[i])
	{
		flags = ft_init_flags();
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i = ft_parse_flags(i, str, &flags);
			if (str[i] != '\0' && flags.specifier > 0 && \
			ft_isspecifiertype(str[i]))
				count += ft_handle_format(str[i], flags, args);
			else if (str[i] != '\0')
				count += ft_print_char(str[i], flags);
		}
		else if (str[i] != '%')
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
