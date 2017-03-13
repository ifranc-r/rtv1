
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/13 15:12:54 by ifranc-r          #+#    #+#              #
#    Updated: 2017/03/13 16:05:45 by ifranc-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
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
	  srcs/obj/init_sceen.c\
	  srcs/obj/intersection.c\
	  srcs/sdl_fct/sdl_init.c\
	  srcs/draw/ray_tracing.c\
	  srcs/draw/vect_operator.c\
	  srcs/event/loop.c\
	  srcs/get_parameter_obj/get_parameter.c\
	  srcs/lightandcolor/light.c\
	  srcs/parse/parse.c\
	  srcs/parse/get_param.c\
	  srcs/parse/get_param2.c\
	  srcs/parse/fnct_value.c\
	  srcs/parse/error.c

SDL = -L ./libft/ -lft  -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2

GCC = gcc -Wall -Wextra -Werror 

LDFLAGS = $(SDL)

OBJ = $(SRC:.c=.o)
OBJS = $(notdir $(OBJ))

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${_CYAN}Start${_END} to compile-> ${_BLUE}${_IWHITE}RTV1${_END}"
	@echo " | "
	@echo " \/ "
	@make -C libft/
	@$(GCC) -o $(NAME) $(OBJ) $(SDL)
	@echo " | "
	@echo " \/ "
	@echo "${_GREEN}Succes${_END}-> ${_BLUE}${_IWHITE}RTV1${_END} as been compile"
	@clear
	@cat ascii/rt.ascii

$(OBJS).o : %.c
	@$(GCC) -I libft/ -I includes/ -c $(OBJS)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJ)
	@echo "${_BLUE}${_IWHITE}RTV1${_END} : ${_PURPLE}Delete${_END}-> -*.o-"
	@make clean -C libft/

fclean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJ)
	@echo "${_BLUE}${_IWHITE}RTV1${_END} : ${_PURPLE}Delete${_END}-> -*.o-"
	@make fclean -C libft/
	@rm -rf $(NAME)
	@echo "${_BLUE}${_IWHITE}RTV1${_END}: ${_PURPLE}Delete${_END}-> ${_BLUE}${_IWHITE}rtv1${_END}"

re: fclean all

pro: fclean all clean