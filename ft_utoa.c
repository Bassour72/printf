/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:44:58 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/21 14:16:49 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_utoa_len(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*ft_u_to_str(unsigned int num, char *str, size_t len)
{
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	len--;
	while (len)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	str[0] = (num % 10) + '0';
	return (str);
}

char	*ft_utoa(unsigned int num)
{
	size_t	len;
	char	*str;

	len = ft_utoa_len(num);
	str = 0;
	str = ft_u_to_str(num, str, len);
	if (!str)
		return (NULL);
	return (str);
}
