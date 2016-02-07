##
## Makefile for makefile in /home/theis_p/git/Piscine_C_J10
##
## Made by Paul THEIS
## Login   <theis_p@epitech.net>
##
## Started on  Fri Oct  9 09:30:41 2015 Paul THEIS
## Last update Sun Feb  7 23:41:37 2016 bougon_p
##

SRCS	=	my_find_prime_sup.c			\
		my_memset.c				\
		my_bzero.c				\
		my_malloc.c				\
		my_getnbr.c				\
		my_isneg.c				\
		my_is_prime.c				\
		my_power_rec.c				\
		my_putchar.c				\
		my_putnbr.c				\
		my_putstr.c				\
		my_revstr.c				\
		my_showmem.c				\
		my_show_str.c				\
		my_sort_int_tab.c			\
		my_square_root.c			\
		my_strcapitalize.c			\
		my_strcat.c				\
		my_strcmp.c				\
		my_strcpy.c				\
		my_str_isalpha.c			\
		my_str_islower.c			\
		my_str_isnum.c				\
		my_str_isprintable.c			\
		my_str_isupper.c			\
		my_strlcat.c				\
		my_strlen.c				\
		my_strlowcase.c				\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strstr.c				\
		my_strupcase.c				\
		my_strdup.c				\
		my_str_to_word_tab.c			\
		my_swap.c				\
		my_atoi.c				\
		my_putstr_err.c				\
		my_char_isprintable.c			\
		my_char_isalpha.c			\
		my_char_isnum.c				\
		my_putnbr_base.c			\
		my_printf/src/check.c			\
		my_printf/src/init.c			\
		my_printf/src/my_printf.c		\
		my_printf/src/swrite.c			\
		my_printf/src/sizer.c			\
		my_printf/src/stock.c			\
		my_printf/src/tool.c			\
		my_printf/src/print/print_all_str.c	\
		my_printf/src/print/print_char.c	\
		my_printf/src/print/print_hex.c		\
		my_printf/src/print/print_big_hex.c	\
		my_printf/src/print/print_octal.c	\
		my_printf/src/print/print_str.c		\
		my_printf/src/print/print_binary.c	\
		my_printf/src/print/print_int.c		\
		my_printf/src/print/print_ptr.c		\
		my_printf/src/print/print_uint.c	\
		get_next_line.c				\

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic

NAME	= libmy.a

NEW_N	= ../../../libmy.a

OBJS	= $(addprefix src/, $(SRCS:.c=.o))

HEADER  = include/my.h

NEW_H	= ../../include/my.h

CC	= gcc

CP	= cp -f

RM	= rm -f

AR	= ar

$(NAME)	:	$(OBJS)
		@$(AR) rc $(NAME) $(OBJS)
		@$(CP) $(HEADER) $(NEW_H)
		@$(CP) $(NAME) $(NEW_N)

all	:	$(NAME)

clean	:
		@$(RM) $(OBJS)

fclean	: 	clean
		@$(RM) $(NAME) $(NEW_N) $(NEW_H)

re	: 	fclean all
