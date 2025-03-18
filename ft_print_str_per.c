/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_per.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:49:27 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/24 10:25:51 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str_per(const char *str, int precision)
{
	int	count;

	count = 0;
	while (str[count] && count < precision)
		ft_putchar(str[count++]);
	return (count);
}
