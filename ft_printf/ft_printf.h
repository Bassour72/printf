/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:53:02 by ybassour          #+#    #+#             */
/*   Updated: 2024/11/30 02:12:05 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnstr(const char *str, int len);
int	ft_counthex(unsigned long number);
int	ft_numsize(unsigned int n);
int	ft_paddingspace(int len, char pad_char);
int	ft_putaddress(void *address);
int	ft_putunbr(unsigned int un);
int	ft_putnbr(int n);
int	ft_puthexnbr(unsigned int nbr, char format);
int	ft_countint(int n);
int	ft_handle_format(char spe, va_list args, const char *format, int *len);
int	ft_handle_dash(const char *format, va_list arg, int *format_len);
int	ft_handle_zero(const char *format, va_list arg, int *format_len);
int	ft_handle_decimal_point(const char *format, va_list arg, int *format_len);
int	ft_handle_hash_sign(const char *format, va_list arg, int *format_len);
int	ft_handle_space(const char *format, va_list arg, int *format_len);
int	ft_handle_plus_sign(const char *format, va_list arg, int *format_len);
int	ft_handle_digits(const char *format, va_list arg, int *format_len);
int	ft_isnumber(const char *str, int *value);
int	ft_countdigits(int n);
int	ft_countdigits_unsigned(unsigned int n);
int	ft_handle_string_all(int len, va_list arg, char padd_char);
int	ft_handle_string(int len, va_list arg);
int	ft_putlnbr(int nu);
int	ft_putllnbr(int nu);
#endif
