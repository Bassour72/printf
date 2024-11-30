/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:00:30 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/28 18:47:59 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned long n)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16);
	write(1, &hex[n % 16], 1);
	return (len + 1);
}

int	ft_putaddress(void *ptr)
{
	unsigned long	address;
	int				len;

	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	address = (unsigned long)ptr;
	write(1, "0x", 2);
	len = 2;
	len += ft_puthex(address);
	return (len);
}
