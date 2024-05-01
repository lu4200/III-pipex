# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 14:37:22 by lumaret           #+#    #+#              #
#    Updated: 2024/05/01 18:22:52 by lumaret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	pipex.c \
			free.c \
			error.c \
			utils.c \
			ft_strstr.c \
			exec_child.c \

LIBFTDIR =	libft/

HEADER	=	pipex.h

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc -no-pie -g3

CFLAGS	=	-Wall -Wextra -Werror -fPIE

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft

%.o 	:	%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			@rm -f $(OBJS) $(NAME)

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean all

libft	:
			@make -C libft
