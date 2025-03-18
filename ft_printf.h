/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 23:56:12 by ybassour          #+#    #+#             */
/*   Updated: 2024/12/24 18:40:24 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	width;
	int	precision;
	int	specifier;
	int	hash;
	int	plus;
	int	zero;
	int	space;
	int	left;
	int	boolean;
}	t_flags;

int		ft_printf(const char *format, ...);
int		ft_parse(const char *str, va_list args);
int		ft_handle_format(char c, t_flags flags, va_list args);
t_flags	ft_init_flags(void);
t_flags	ft_flags_left(t_flags flags);
int		ft_flags_width(t_flags *flags, const char *str, int pos);
int		ft_parse_flags(int i, const char *str, t_flags *flags);
int		ft_flags_precision(int i, const char *str, t_flags *flags);
int		ft_isflgs(char c);
int		ft_isspecifiertype(char c);
int		ft_isutils_format_flags(char c);
int		ft_putchar(char c);
int		ft_paddingsporze(int total_width, int size, int boolean);
int		ft_print_char(char c, t_flags flags);
int		ft_print_str(const char *str, t_flags flags);
int		ft_print_str_per(const char *str, int precision);
int		ft_print_integer(char *nbstr, int n, t_flags flags);
char	*ft_itoa(long num);
int		ft_print_sign_prec(int n, t_flags *flags);
int		ft_print_i(char *nbstr, int n, t_flags flags);
int		ft_print_hex(unsigned int n, char upper, t_flags flags);
char	*ft_xtoa(unsigned long int num, int is_upper);
int		ft_print_hexadecmal(char *nbstr, int n, int is_upper, t_flags flags);
int		ft_print_hex_prefix(int is_upper);
int		ft_print_x(char *nbstr, int n, int is_upper, t_flags flags);
int		ft_print_unsigned(unsigned int n, t_flags flags);
int		ft_print_unint(char *nbstr, t_flags flags);
int		ft_print_address(unsigned long int n, t_flags flags);
int		ft_ptr_len(unsigned long int n);
int		ft_print_int(int n, t_flags flags);
int		ft_print_string_a(const char *str);
char	*ft_utoa(unsigned int num);
int		ft_print_u(char *nbstr, t_flags flags);
int		ft_isdigit(int c);
void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *b, size_t n);
#endif