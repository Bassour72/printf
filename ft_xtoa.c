/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:45:34 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/21 15:17:39 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_xtoa_len(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static char	*ft_hex_to_str(unsigned long int num, char *str, size_t len)
{
	int	mod;

	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	len--;
	while (len != (size_t)-1)
	{
		mod = num % 16;
		if (mod < 10)
			str[len] = mod + '0';
		else if (mod >= 10)
			str[len] = (mod - 10) + 'a';
		num = num / 16;
		len--;
	}
	return (str);
}

char	*ft_xtoa(unsigned long int num, int is_upper)
{
	size_t	len;
	char	*str;
	int		i;

	len = ft_xtoa_len(num);
	str = 0;
	str = ft_hex_to_str(num, str, len);
	if (!str)
		return (NULL);
	if (is_upper == 1)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= 32;
			i++;
		}
	}
	return (str);
}
