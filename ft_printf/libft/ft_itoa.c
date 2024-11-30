/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:33:47 by ybassour          #+#    #+#             */
/*   Updated: 2024/10/29 23:46:31 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nsize(int n)
{
	int		i;
	int		count;
	long	x;

	x = n;
	i = 0;
	count = 0;
	if (x == 0)
		return (1);
	if (x < 0)
	{
		x = x * -1;
		count++;
	}
	while (x > 0)
	{
		x /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	nsize;
	long	number;
	size_t	i;
	char	*p;

	i = 0;
	nsize = ft_nsize(n);
	p = malloc(nsize + 1);
	if (!p)
		return (NULL);
	number = n;
	if (number < 0)
	{
		p[0] = '-';
		number = number * -1;
		i++;
	}
	p[nsize] = '\0';
	while (i < nsize)
	{
		p[--nsize] = (number % 10) + 48;
		number /= 10;
	}
	return (p);
}
