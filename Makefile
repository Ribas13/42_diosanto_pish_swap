# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 16:16:10 by diosanto          #+#    #+#              #
#    Updated: 2023/06/29 23:01:50 by ribs             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
RM		= rm -f

SRCS 	=  ${wildcard SRCS/*.c}

OBJS	= $(SRCS:c=o)

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM)  $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:  fclean $(NAME)

.PHONY: all clean fclean re