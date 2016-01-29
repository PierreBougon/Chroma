##
## Makefile for PAINT in /home/bougon_p/rendu/gfx_tekpaint
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Mon Jan  4 19:12:16 2016 bougon_p
## Last update Wed Jan 27 07:00:41 2016 bougon_p
##

TOOLS	=	src/tools/

INT	=	src/gui/

LINE	=	src/line/

MAIN	=	src/main/

PEN	=	src/pen/

FILTER	=	src/filter/

LIST	=	src/list/

BUCKET	=	src/bucket/

CIRCLE	=	src/circle/

ERASER	=	src/eraser/

SQUARE	=	src/square/

THE_PEN	=	src/the_pen/

BACK	=	src/back/

SRC	=	$(MAIN)tekpaint.c 	\
		$(MAIN)display.c 	\
		$(MAIN)free.c \
		$(MAIN)util.c 		\
		$(MAIN)replace.c \
		$(MAIN)init.c \
		$(MAIN)init_butt.c \
		$(PEN)draw_pen.c 			\
		$(PEN)inter_pt.c 			\
		$(TOOLS)draw_rec.c 		\
		$(TOOLS)draw_line.c 	\
		$(TOOLS)tekpixel.c 		\
		$(TOOLS)font.c 				\
		$(TOOLS)setnbr.c 				\
		$(TOOLS)curs.c 				\
		$(INT)nuancier.c 			\
		$(INT)swatch.c 			\
		$(INT)act_button.c 		\
		$(LIST)list.c					\
		$(LIST)list2.c				\
		$(LIST)list3.c				\
		$(LIST)list4.c				\
		$(LIST)list5.c				\
		$(LIST)button.c				\
		$(LIST)calc.c				\
		$(FILTER)grey.c \
		$(FILTER)invers.c \
		$(BUCKET)bucket.c \
		$(BUCKET)get_col.c \
		$(ERASER)erase.c \
		$(CIRCLE)circle.c \
		$(SQUARE)square.c \
		$(THE_PEN)the_pen.c \
		$(BACK)background.c \
		$(LINE)line.c \

OBJS    =	$(SRC:.c=.o)

LIBPATH =	lib/my/src/

NAME    =	tekpaint

IFLAG	=	-Iinclude/

CC      =	gcc $(CFLAGS) $(IFLAG)

CFLAGS  =	-W -Wextra -Wall -Werror -ansi -pedantic

LDFLAGS =	-lmy -L$(LIBPATH) \

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

MAKE 	= 	make

$(NAME)	: $(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LIB) $(LDFLAGS) $(IFLAG)
		@echo "$(GREEN)\n> Compiling sources\t : \t DONE\n$(WHITE)"

$(CPLIB) : $(MAKE) -C lib/my/

all	:	$(CPLIB) $(NAME)

clean	:
		@$(RM) $(OBJS)
		@echo "$(GREEN)\n> Cleaning repository\t : \t DONE\n$(WHITE)"

fclean	: 	clean
		$(MAKE) fclean -C lib/my/
		@$(RM) $(NAME)
		@echo "$(GREEN)\n> Cleaning exec\t\t : \t DONE\n$(WHITE)"

re	:	fclean all

.c.o	:
		@gcc $(IFLAG) -c $< -o $@ $(FLAG) $(CFLAGS)
		@echo "$(GREEN)> $<\t : \t [OK]$(WHITE)"
