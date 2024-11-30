/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:12:23 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 02:27:55 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putllnbr(int nu)
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
		ft_putllnbr(n / 10);
		ft_putllnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (ft_countint(nu));
}
