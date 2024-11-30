/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:27:26 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 02:20:07 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countint(int nu)
{
	int			size;
	long long	n;

	n = nu;
	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n = n * -1;
	}
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}
