# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 19:57:34 by gychoi            #+#    #+#              #
#    Updated: 2022/11/17 21:29:04 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS =
RM = rm -f

SRCS = push_swap.c \
	param_utils.c \
	deque_utils.c \
	list_utils.c \
	op_push.c \
	op_rotate.c \
	op_reverse_rotate.c \
	op_swap.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY : all clean fclean re
