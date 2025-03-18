/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybassour <ybassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:40:43 by ybassour          #+#    #+#             */
/*   Updated: 2025/03/18 18:33:42 by ybassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


NAME			=	libftprintf.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	ft_printf.c ft_putaddress.c ft_putchar.c		\
					ft_puthexnbr.c ft_putnbr.c ft_putstr.c 			\
					ft_putunbr.c ft_handle_format.c ft_handle_dash.c \
					ft_handle_decimal_point.c  ft_handle_digits.c		\
					ft_handle_hash_sign.c ft_handle_plus_sign.c ft_handle_space.c \
					ft_handle_zero.c ft_paddingspace.c ft_putnstr.c ft_numsize.c ft_counthex.c ft_countint.c \
					ft_isnumber.c ft_countdigits.c ft_countdigits_unsigned.c ft_handle_string_all.c ft_handle_string.c \
					ft_putlnbr.c ft_putllnbr.c
SRCS 			=	$(SRC)

OBJ_DIR			=	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
				cp	$(LIBFT) $(NAME)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re libft