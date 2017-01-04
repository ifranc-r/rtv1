NAME = rtv1

SRC = ./srcs/main.c\
	  srcs/sdl_fct/sdl_init.c\
	  srcs/draw/ray_plane.c\
	  srcs/event/loop.c\

SDL = -L ./libft/ -lft  -framework SDL2

GCC = gcc -Wall -Wextra -Werror 

LDFLAGS = $(SDL)

OBJ = $(SRC:.c=.o)
OBJS = $(notdir $(OBJ))

.PHONY: clean fclean

all: $(NAME)

$(NAME):
	@make -C libft/
	@$(GCC) -c $(SRC) -I libft/ -I includes/
	@$(GCC) -o $(NAME) $(OBJS) $(SDL)
	@echo Génération en mode debug


clean:
	@rm -rf $(OBJS)
	@make fclean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/

re: fclean all
	@make re -C libft/