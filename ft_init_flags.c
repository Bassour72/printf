/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:10:45 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/21 16:57:52 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.hash = 0;
	flags.left = 0;
	flags.plus = 0;
	flags.precision = -1;
	flags.space = 0;
	flags.width = 0;
	flags.zero = 0;
	flags.boolean = -1;
	return (flags);
}
