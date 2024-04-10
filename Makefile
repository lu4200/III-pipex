# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 16:56:17 by lumaret           #+#    #+#              #
#    Updated: 2024/04/10 14:41:33 by lumaret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRC_DIR = mandatory
SRCS = $(SRC_DIR)/pipex.c $(SRC_DIR)/utils.c $(SRC_DIR)/free.c $(SRC_DIR)/error.c
BONUS_DIR = bonus
BONUS = $(BONUS_DIR)/pipex_bonus.c $(BONUS_DIR)/multipipe.c $(BONUS_DIR)utils_bonus.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(NAME)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

