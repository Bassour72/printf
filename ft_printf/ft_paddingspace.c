/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddingspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:49:14 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 01:42:45 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_paddingspace(int len, char pad_char)
{
	int	total;

	total = 0;
	while (len > 0)
	{
		write(1, &pad_char, 1);
		len--;
		total++;
	}
	return (total);
}
