/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:51:07 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/21 12:56:45 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
		count += ft_putchar(c);
	count += ft_paddingsporze(flags.width, 1, flags.zero);
	if (flags.left == 0)
		count += ft_putchar(c);
	return (count);
}
