/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:29:51 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/29 02:49:54 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_hex(unsigned int n, const char *hex)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_hex(n / 16, hex);
	}
	write(1, &hex[n % 16], 1);
	return (count + 1);
}

int	ft_puthexnbr(unsigned int nbr, char format)
{
	unsigned long	u_n;
	char			*hexlo;
	char			*hexup;

	u_n = (unsigned long)nbr;
	if (format == 'x')
	{
		hexlo = "0123456789abcdef";
		return (ft_hex(nbr, hexlo));
	}
	else
	{
		hexup = "0123456789ABCDEF";
		return (ft_hex(nbr, hexup));
	}
}
