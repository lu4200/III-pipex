# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas <lucas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 14:37:22 by lumaret           #+#    #+#              #
#    Updated: 2024/05/17 20:45:45 by lucas            ###   ########.fr        #
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
LIBFT	= $(LIBFTDIR)libft.a

HEADER	=	pipex.h

OBJS	=	$(SRCS:%.c=%.o)

CC		=	cc -g3

CFLAGS	=	-Wall -Wextra -Werror -fPIE

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft

%.o 	:	%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			@rm -f $(OBJS) $(NAME)

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean all

$(LIBFT):
			@make -C libft
