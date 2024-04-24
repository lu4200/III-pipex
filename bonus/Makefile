# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 14:37:22 by lumaret           #+#    #+#              #
#    Updated: 2024/04/22 15:05:50 by lumaret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	main.c \
			ft_split.c \
			ft_utils.c \
			ft_multipipe.c \

HEADER	=	pipex.h

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc -g3

CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o 	:	%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			@rm -f $(OBJS)

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean all



