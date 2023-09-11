# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 15:39:30 by ecorvisi          #+#    #+#              #
#    Updated: 2023/09/09 17:53:40 by ecorvisi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -g3
CPPFLAGS = -Iinc

NAME = cub3D
LIB = libft/libft.a
LIBFT_FLAGS = -L libft -lft

SRC_DIR = src
OBJ_DIR = obj
DIR_OBJS = mkdir -p $(@D)

SRC = 	main.c\
		init.c \
		gnl/get_next_line_cub.c\
		gnl/get_next_line_utils_cub.c\
		parsing/parsing.c \
		free/free.c

SRCS = $(SRC:%=$(SRC_DIR)/%)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[1;4m\033[1;33m                       \033[0m"
	@echo "\033[1;4m\033[1;33m\033[1;1m*      COMPILING      *\033[0m"
	@make bonus -s -C libft
	@$(CC) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(LIB) -lreadline
	@echo "\033[1;4m\033[1;32m                            \033[0m"
	@echo "\033[1;4m\033[1;32m\033[1;1m*      CUB3D COMPILED      *\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_OBJS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJS) $(OBJ_DIR)
	@make clean -s -C libft
	@echo "\033[1;4m\033[1;34m                                     \033[0m"
	@echo "\033[1;4m\033[1;34m\033[1;1m*      DELETING OBJS DIRECTORY      *\033[0m"
	
fclean:
	@rm -rf $(OBJS) $(OBJ_DIR)
	@rm -rf $(NAME)
	@make fclean -s -C libft
	@echo "\033[1;4m\033[1;31m                                 \033[0m"
	@echo "\033[1;4m\033[1;31m\033[1;1m*      CLEANING ALL BINARY      *\033[0m"

re: fclean all

.PHONY: all clean fclean re
