/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_prefix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:55:39 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/24 18:04:24 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_prefix(int is_upper)
{
	if (is_upper == 1)
		ft_print_string_a("0X");
	else
		ft_print_string_a("0x");
	return (2);
}
