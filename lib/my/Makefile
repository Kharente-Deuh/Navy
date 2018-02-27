##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

AR	=	ar rc

RM 	=	rm -f

MK	=	mkdir -p

CP	=	cp

MY	=	lib/my.h

SRC	+=	get_next_line.c
SRC	+=	my_str_to_word_tab.c
SRC	+=	my_compute_power_it.c
SRC	+=	my_itoa.c
SRC	+=	str_functions.c
SRC	+=	my_strdup_strcmp.c
SRC	+=	tab_functions.c
SRC	+=	my_getnbr.c
SRC	+=	my_strisnb.c

OBJDIR	=	obj/

SRCDIR = 	src/

OBJ	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

CLFAG	+=	-W
CFLAG	+=	-Wall
CFLAG	+=	-Wextra
CFLAG	+=	-g3

LDLIB	=	-Iinclude/

NAME	=	libmy.a

$(OBJDIR)%.o:	$(SRCDIR)%.c
	@$(MK) $(OBJDIR)
	@$(CC) $(CFLAG) $(LDLIB) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(CP) include/my.h ../../include/my.h
	@mv $(NAME) ../

clean:
	@$(RM) -r $(OBJDIR)

fclean: clean
	@$(RM) ../$(NAME)

re:	fclean all

.PHONY: clean fclean re all
