/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:48:11 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 02:27:06 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlnbr(int nu)
{
	long	n;

	n = nu;
	if (n == -2147483648)
	{
		write(1, "2147483648", 11);
		return (11);
	}
	if (n < 0)
		n = n * -1;
	if (n >= 10)
	{
		ft_putlnbr(n / 10);
		ft_putlnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (ft_countint(nu));
}
