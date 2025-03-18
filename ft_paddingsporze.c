/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddingsporze.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:23:53 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/02 17:07:00 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_paddingsporze(int total_width, int size, int boolean)
{
	int	count;

	count = 0;
	while (total_width - size > 0)
	{
		if (boolean)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
		total_width--;
	}
	return (count);
}
