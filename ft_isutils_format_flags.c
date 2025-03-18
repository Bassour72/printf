/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isutils_format_flags.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:24:36 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/24 11:29:02 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isutils_format_flags(char c)
{
	return (ft_isdigit(c) || ft_isflgs(c) || ft_isspecifiertype(c));
}
