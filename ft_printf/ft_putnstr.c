/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:51:08 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 01:37:20 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnstr(const char *str, int len)
{
	int	total;

	total = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str != '\0' && len > 0)
	{
		write (1, str++, 1);
		len--;
		total++;
	}
	return (total);
}
