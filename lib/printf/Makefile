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

LIBDIR	=	../libprtf.a

SRC	=	my_printf.c			\
		conv_base.c			\
		base_flags.c			\
		put_functions.c			\
		str_functions.c			\
		put_unsigned.c

OBJDIR	=	obj/

SRCDIR = 	src/

OBJ	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

CLFAG	+=	-W
CFLAG	+=	-Wall
CFLAG	+=	-Wextra

LDLIB	=	-Iinclude/

NAME	=	libprtf.a

$(OBJDIR)%.o:	$(SRCDIR)%.c
	@$(MK) $(OBJDIR)
	@$(CC) $(CFLAG) $(LDLIB) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@mv $(NAME) $(LIBDIR)
	@$(CP) include/printf.h ../../include/printf.h
clean:
	@$(RM) -r $(OBJDIR)

fclean: clean
	@$(RM) $(LIBDIR)

re:	fclean all

.PHONY: clean fclean re all
