# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/28 07:38:34 by ygaude            #+#    #+#              #
#    Updated: 2018/06/29 07:23:03 by ygaude           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			picksim

PATH_LIBFT =	libft/
LIBFT =			libft/libft.a

PATH_SRC =		src/
PATH_OBJ =		obj/

CC =			gcc -Wall -Wextra
CFLAGS =		-I include/ -I libft/include/ `sdl2-config --cflags`
LFLAGS =		-L $(PATH_LIBFT) -lft `sdl2-config --libs` -lSDL2_ttf -lSDL2_gfx

SRC =			events.c picksim.c sdltools.c visu_init.c visualize.c visutools.c

OBJ =			$(patsubst %.c, $(PATH_OBJ)%.o, $(SRC))

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "Compiling $@ ..."
	@$(CC) $^ -o $@ $(LFLAGS)
	@echo "Done !"

$(LIBFT):
	make -C $(PATH_LIBFT)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@echo "Compiling $@"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(PATH_OBJ)
	@make -C $(PATH_LIBFT) clean
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@make -C $(PATH_LIBFT) fclean
	@echo "$(NAME) and $(LIBFT) removed."

re: fclean all

.PHONY: all clean fclean libft
