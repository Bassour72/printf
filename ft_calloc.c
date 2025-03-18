/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:07:51 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/16 00:12:53 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if (n && (n * size) / n != size)
		return (NULL);
	ptr = (void *)malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}
