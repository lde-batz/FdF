# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 11:55:15 by lde-batz          #+#    #+#              #
#    Updated: 2019/01/19 15:59:52 by lde-batz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = 	main.c\
		graph.c\
		map.c\
		read_map.c\
		read_color.c\
		link.c\
		img.c\
		home.c\
		circle.c\
		control.c\
		carre.c\
		clic1.c\
		clic2.c\
		clic3.c\
		segment.c\
		segment_1st_half.c\
		segment_2nd_half.c\
		segment_straight.c\
		key.c\
		key_fct.c\
		move.c\
		altitude.c\
		zoom.c\
		opacity.c\
		print_map.c\
		mouse.c\
		clic2b.c\
		clic3b.c\
		segment_fct.c\
		segment_fct2.c\
		color_fct.c\

SRC_DIR = srcs/

OBJ_DIR = objects/

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC := $(addprefix $(SRC_DIR), $(SRC))

INC =	-I includes/fdf.h -I libft/srcs/libft.h

LIB = -L libft/ -lft -L /usr/local/lib/ -lmlx

GCC = gcc -Wall -Wextra -Werror

MLX_FLAG = -framework OpenGL -framework AppKit

.SILENT:

all: lib $(NAME)

$(NAME): $(OBJ)
	$(GCC) -o $(NAME) $(SRC) $(LIB) $(MLX_FLAG)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create FdF"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(GCC) -c $< -o $@ $(INC)
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

lib:
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJ)
	rm -Rf $(OBJ_DIR)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean FdF"

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean FdF"

re: fclean all

.PHONY: all clean fclean re
