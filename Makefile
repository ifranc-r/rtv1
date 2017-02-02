
# This is a minimal set of ANSI/VT100 color codes
_END=\x1b[0m
_BOLD=\x1b[1m  
_UNDER=\x1b[4m
_REV=\x1b[7m

# Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY=\x1b[40m
_IRED=\x1b[41m
_IGREEN=\x1b[42m
_IYELLOW=\x1b[43m
_IBLUE=\x1b[44m
_IPURPLE=\x1b[45m
_ICYAN=\x1b[46m
_IWHITE=\x1b[47m

NAME = rtv1

SRC = ./srcs/main.c\
	  srcs/obj/init_obj.c\
	  srcs/sdl_fct/sdl_init.c\
	  srcs/draw/ray_plane.c\
	  srcs/draw/color_operator.c\
	  srcs/draw/vect_operator.c\
	  srcs/event/loop.c\

SDL = -L ./libft/ -lft  -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2

GCC = gcc -Wall -Wextra -Werror 

LDFLAGS = $(SDL)

OBJ = $(SRC:.c=.o)
OBJS = $(notdir $(OBJ))

.PHONY: clean fclean

all: $(NAME)

$(NAME):
	@echo "${_CYAN}Start${_END} to compile-> ${_BLUE}${_IWHITE}RTV1${_END}"
	@echo " | "
	@echo " \/ "
	@make -C libft/
	@$(GCC) -c $(SRC) -I libft/ -I includes/ 
	@$(GCC) -o $(NAME) $(OBJS) $(SDL)
	@echo " | "
	@echo " \/ "
	@echo "${_GREEN}Succes${_END}-> ${_BLUE}${_IWHITE}RTV1${_END} as been compile"


clean:
	@rm -rf $(OBJS)
	@echo "${_BLUE}${_IWHITE}RTV1${_END} : ${_PURPLE}Delete${_END}-> -*.o-"
	@make clean -C libft/

fclean:
	@rm -rf $(OBJS)
	@echo "${_BLUE}${_IWHITE}RTV1${_END} : ${_PURPLE}Delete${_END}-> -*.o-"
	@make fclean -C libft/
	@rm -rf $(NAME)
	@echo "${_BLUE}${_IWHITE}RTV1${_END}: ${_PURPLE}Delete${_END}-> ${_BLUE}${_IWHITE}rtv1${_END}"

re: fclean all

pro: fclean all clean