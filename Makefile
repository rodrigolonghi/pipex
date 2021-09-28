# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 19:51:31 by rfelipe-          #+#    #+#              #
#    Updated: 2021/09/27 22:42:13 by rfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = libft/libft.a

SRC_DIR = src
SRC = $(SRC_DIR)/pipex.c \
		$(SRC_DIR)/check_arguments.c

INCLUDE_DIR = includes
INCLUDE = $(INCLUDE_DIR)/pipex.h

OBJ_DIR = objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -lm $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all
