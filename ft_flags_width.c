/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:52:35 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/24 11:58:21 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags_width(t_flags *flags, const char *str, int pos)
{
	int	boolean;

	boolean = -1;
	flags->width = 0;
	while (ft_isdigit(str[pos]))
	{
		flags->width = (flags->width * 10) + (str[pos] - '0');
		pos++;
		boolean = 1;
	}
	if (boolean == 1)
		pos--;
	return (pos);
}
