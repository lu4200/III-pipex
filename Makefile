# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 16:56:17 by lumaret           #+#    #+#              #
#    Updated: 2024/03/17 16:59:03 by lumaret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS = pipex.c utils.c
OBJS = ${SRCS:.c=.o}
MAIN = pipex.c

LIBFT_A = libft.a
LIBF_DIR = Libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

CC 		 = gcc
CFLAGS 	 = -Wall -Wextra -Werror -g3

all:		$(NAME)

clean:
					@make clean -C ./libft

fclean: 	clean
					@make -C $(LIBF_DIR) fclean
					@rm -f $(NAME)
					@rm -f ${PROG}

re:			fclean all