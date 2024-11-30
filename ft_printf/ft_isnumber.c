/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:26:52 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 01:43:37 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isnumber(const char *str, int *value)
{
	int	result;
	int	is_number;

	result = 0;
	is_number = 0;
	*value = 0;
	while (*str >= '0' && *str <= '9')
	{
		is_number++;
		result = result * 10 + (*str - '0');
		str++;
	}
	if (is_number)
		*value = result;
	return (is_number);
}
