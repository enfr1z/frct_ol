# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 17:23:28 by pdiedra           #+#    #+#              #
#    Updated: 2019/06/06 15:13:55 by pdiedra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME 			= fractol
NAME_LIB		= ./libft/libft.a

SRC_PATH		= ./src/
INCLUDE_PATH	= ./includes/
LIBFT_PATH		= ./libft
OBJ_DIR			= ./obj/

SRC_NAME		= construct.c mouse.c keyboard.c main.c mandelbrot.c burning_ship.c julia.c
HEADER_NAME		= fractol.h keys.h
OBJ_NAME		= $(SRC_NAME:.c=.o)

SRC				= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ				= $(addprefix $(OBJ_DIR), $(OBJ_NAME))
HEADER 			= $(addprefix $(INCLUDE_PATH), $(HEADER_NAME))

FLAG			= -Wall -Wextra -Werror

MLX				= -L minilibx/ -lmlx -framework OpenGL -framework AppKit

CC				= gcc

RED			=\033[0;31m
GREEN		=\033[0;32m
BLUE		=\033[0;34m
YELLOW		=\033[0;33m

all: $(NAME)
  
$(NAME): $(OBJ_DIR) $(NAME_LIB) $(OBJ)
	@$(CC) $(OBJ) -L $(LIBFT_PATH) -lft -o $(NAME) $(FLAG) $(MLX)
	@echo "\t\t\t\t\033[0;42mFractal is ready!"

$(OBJ_DIR):
	@mkdir -p obj
	@echo "\t\t\t\t$(YELLOW)Dir is create..."

$(OBJ_DIR)%.o: $(SRC_PATH)%.c $(HEADER)
	@echo "$(BLUE)$(CC) -c -I $(INCLUDE_PATH) -I $(LIBFT_PATH)/$(INCLUDE_PATH) $(FLAG) $< -o $@"
	@$(CC) -c -I $(INCLUDE_PATH) -I $(LIBFT_PATH)/$(INCLUDE_PATH) $(FLAG) $< -o $@

$(NAME_LIB):
	@echo "\t\t\t\t$(YELLOW)Compile libft..."
	@make -sC $(LIBFT_PATH)

relib:
	@make re -sC $(LIBFT_PATH)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME_LIB)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC $(LIBFT_PATH)

re: fclean all