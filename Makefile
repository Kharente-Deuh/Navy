##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

P	=	\033[35m
B	=	\033[34m
Y	=	\033[33m
R	=	\033[31m
G	=	\033[32m
W	=	\033[39m
C	=	\033[36m

CLEAR	=	echo "\033c"

CC	=	gcc

RM	=	rm -f

MK	=	mkdir -p

MV	=	mv

SRC	+=	main.c
SRC	+=	usage.c
SRC	+=	init_players.c
SRC	+=	map_functions.c
SRC	+=	run_game.c
SRC	+=	atk_and_def.c
SRC	+=	protocol.c

OBJDIR 	=	obj/

SRCDIR 	=	src/

LIBPRTF	=	make --no-print-directory -C lib/printf/

LIBMY	=	make --no-print-directory -C lib/my/

LIBPRR	=	make --no-print-directory -C lib/perror/

OBJ	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

NAME	=	navy

CFLAG	+=	-W
CFLAG	+=	-Wall
CFLAG	+=	-Wextra
CFLAG	+=	-g

LDLIBS	+=	-Llib/
LDLIBS	+=	-lmy
LDLIBS	+=	-lprtf
LDLIBS	+=	-lprr
LDLIBS	+=	-Iinclude/

$(OBJDIR)%.o:	$(SRCDIR)%.c
	@$(MK) $(OBJDIR)
	@$(CC) $(CFLAG) $(LDLIBS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(LIBMY)
	@$(LIBPRTF)
	@$(LIBPRR)
	@$(CC) -o $(NAME) $(OBJ) $(LDLIBS)
	@echo "\033[1m\033[34mTroncy no Jutsu: $(Y)MEIKU ! (^-^)ゝ\n"
	@echo "$(B)oOoOOoOOo  $(P)OooOOo.    $(B).oOOOo.   $(P)o.     O  "\
	"$(B).oOOOo.  $(P)o       O\n"\
	"    $(B)o      $(P)o     'o  $(B).O     o.  $(P)Oo     o  .O    "\
	"$(B)o  $(P)O       o    $(R)OOO   OOO\n" \
	"   $(B)o      $(P)O      O  $(B)O       o  $(P)O O    O  $(B)o        "\
	"$(P)'o     O'   $(R)O$(Y)ooo$(R)O O$(Y)ooo$(R)O\n" \
	"   $(B)O      $(P)o     .O  $(B)o       O  $(P)O  o   o  o          "\
	"$(P)O   o     $(R)O$(Y)oooo$(R)O$(Y)oooo$(R)O\n" \
	"   $(B)o      $(P)OOooOO'   $(B)O       o  $(P)O   o  O  $(B)o   "\
	"        $(P)'O'       $(R)'O$(Y)ooooo$(R)O'\n"\
	"    $(B)O      $(P)o    o    $(B)o       O  $(P)o    O O  $(B)O"\
	"            $(P)o          $(R)O$(Y)ooo$(R)O\n"\
	"    $(B)O      $(P)O     O   $(B)'o     O'  $(P)o     Oo  $(B)'o"\
	"    .o     $(P)O           $(R)'O'\n"\
	"    $(B)o      $(P)O      o   $(B)'OoooO'   $(P)O     'o  "\
	"$(B)'OoooO'      $(P)O\n"



clean:
	@$(RM) -r $(OBJDIR)
	@$(LIBMY) clean
	@$(LIBPRTF) clean
	@$(LIBPRR) clean
	@echo "\033[1m$(B)Troncy no Jutsu: $(Y)KURINO ! ʕ•ᴥ•ʔ\n$(W)"
	@echo "                  $(Y)<<<<>>>>>>           "\
	"$(C).----------------------------.\n" \
	"              $(Y)_>><<<<>>>>>>>>>       $(C)/                "\
	"_____________)\n"\
	"      $(Y)\\|/      \\<<<<<  < >>>>>>>>>   $(C)/           "\
	" _______________)\n"\
	"$(P)-------$(Y)o$(P)--=====$(Y)<<           <<<<<<<>$(C)/        "\
	" _______________)\n"\
	"      $(Y)/|\\     << $(R)@$(W)    _/      $(Y)<<<<<$(C)/       "\
	"_____________)\n"\
	"            $(Y)<   $(W)\\    /  \\      $(Y)>>>$(C)/      "\
	"________)  ___)\n" \
	"                $(W)|  |   |       $(Y)<$(C)/      "\
	"______)____$(Y)((- \\\\\\\\\\\\\\\\\n" \
	"                $(W)o_|   /        $(C)/      ______)         "\
	"$(W)\\  $(Y)\\\\\\\\\\\\\    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n"\
	"                      $(W)|  ._    $(C)(      ______)           "\
	"$(W)\\  $(Y)\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"\
	"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n" \
	"                     $(W)| /       $(C)'----------'    $(W)/       "\
	"$(W)/     $(Y)\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\     \\\\\\\\\n"\
	"              $(W).______/\\/     /                 /       /   "\
	"         $(Y)\\\\\\\\\\\\\n"\
	"             $(W)/ __.____/    _/         ________(       /\\\\\\n"\
	"            / / / ________/'---------'         \\     /  \\_\n"\
	"           / /  \\ \\                             "\
	"\\   \ \\_  \\\\\\n"\
	"          ( <    \\ \\                             >  /    \\ \\\\\n"\
	"           \\/      \\\\\_                          / /       > )\n"\
	"                    \\_|                        / /       / /\n"\
	"                                             _//       _//\n"\
	"                                            /_|       /_|\n"

fclean: clean
	@$(RM) $(NAME)
	@$(LIBMY) fclean
	@$(LIBPRTF) fclean
	@$(LIBPRR) fclean
	@echo "\033[1m\033[34mTroncy no Jutsu: \033[33mEFUKURINO ! ⋋_⋌\n"
	@echo "                  $(G)    __\n" \
	"                    / $(R)*$(G)_)  \033[36m?\n"\
	"         $(G)_.----. _ /../\n"\
	"       /............./\n"\
	"   __/..(...|.(...|\n"\
	"   /__.-|_|--|_|\n"
re:	fclean all

.PHONY: clean fclean re all
