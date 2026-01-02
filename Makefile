# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/01 18:20:26 by fgoncal2          #+#    #+#              #
#    Updated: 2026/01/02 19:56:27 by fgoncal2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes -Ilibft/includes

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = sources
OBJ_DIR = objects

SRCS = $(SRC_DIR)/push_swap.c \
	   $(SRC_DIR)/swap.c \
	   $(SRC_DIR)/display.c \
	   $(SRC_DIR)/push.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[0;32m✓ make successful\033[0m"

$(LIBFT):
	@make -C $(LIBFT_DIR) --silent

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --silent

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --silent

re: fclean all

.PHONY: all clean fclean re
