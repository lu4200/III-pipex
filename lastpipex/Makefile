# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 14:37:22 by lumaret           #+#    #+#              #
#    Updated: 2024/06/18 16:15:53 by lumaret          ###   ########.fr        #
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

OBJS	=	$(SRCS:%.c=%.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft

%.o 	:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			@rm -f $(OBJS)
			make clean -C $(LIBFTDIR)

fclean	:	clean
			@$(RM) $(NAME) 
			make fclean -C $(LIBFTDIR) 
re		:	fclean all

$(LIBFT):
			@make -C $(LIBFTDIR)
