##
## Makefile for PAINT in /home/bougon_p/rendu/gfx_tekpaint
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Mon Jan  4 19:12:16 2016 bougon_p
## Last update Tue Jan 26 20:36:24 2016 Clémenceau Cedric
##

SRC	=	load.c \
		tekpixel.c

OBJS    =	$(SRC:.c=.o)

NAME    =	extra

IFLAG	=	-I./

CC      =	gcc $(CFLAGS) $(IFLAG) -g

CFLAGS  =	-g -W -Wextra -Wall -ansi -pedantic

RM      =	rm -f

LIB	=       -L/home/${USER}/.froot/lib/ -llapin \
                -lsfml-audio \
                -lsfml-graphics \
		-lsfml-window \
                -lsfml-system \
                -lstdc++ -ldl \
		-lm

FLAG	=       -I/home/${USER}/.froot\

GREEN	=	\033[1;32m

WHITE	=	\033[0m

$(NAME)	: 	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LIB) $(LDFLAGS) $(IFLAG)
		@echo "$(GREEN)\n> Compiling sources\t : \t DONE\n$(WHITE)"

all	:	$(NAME)

clean	:
		@$(RM) $(OBJS)
		@echo "$(GREEN)\n> Cleaning repository\t : \t DONE\n$(WHITE)"

fclean	: 	clean
		@$(RM) $(NAME)
		@echo "$(GREEN)\n> Cleaning exec\t\t : \t DONE\n$(WHITE)"

re	:	fclean all

.c.o	:
		@gcc $(IFLAG) -c $< -o $@ $(FLAG) $(CFLAGS)
		@echo "$(GREEN)> $<\t : \t [OK]$(WHITE)"
