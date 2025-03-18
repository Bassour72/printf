NAME			=	libftprintf.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	r
RM				=	rm -rf

SRC				=	ft_printf.c ft_flags_width.c ft_flags_left.c ft_flags_precision.c  ft_init_flags.c ft_isflgs.c ft_isspecifiertype.c \
					ft_isutils_format_flags.c ft_paddingsporze.c ft_parse_flags.c ft_parse.c ft_itoa.c ft_print_hexadecmal.c ft_print_integer.c \
					ft_print_sign_prec.c ft_print_u.c ft_print_unint.c ft_print_x.c ft_print_address.c ft_print_char.c ft_handle_format.c    \
					ft_print_hex.c ft_print_i.c ft_print_int.c ft_print_string_a.c ft_print_str.c  ft_utoa.c ft_print_hex_prefix.c ft_print_unsigned.c \
					ft_xtoa.c  ft_putchar.c ft_print_str_per.c ft_ptr_len.c  ft_calloc.c ft_isdigit.c ft_strlen.c  \
					ft_bzero.c

OBJS			=	$(SRC:%.c=%.o)


all:				$(NAME)

%.o:		%.c	ft_printf.h
					$(CC) $(CFLAGS) -c $< -o $@
bonus:				all

$(NAME):			$(OBJS)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)
clean:
					
					$(RM) $(OBJS)
fclean:				clean
					
					$(RM) $(NAME)
re:					fclean all

.PHONY:				clean
