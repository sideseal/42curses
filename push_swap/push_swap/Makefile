# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 19:57:34 by gychoi            #+#    #+#              #
#    Updated: 2022/12/04 22:40:12 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = push_swap.c \
	push_swap_utils.c \
	ps_param_utils.c \
	ps_deque_utils.c \
	ps_list_utils.c \
	op_push.c \
	op_rotate.c \
	op_reverse_rotate.c \
	op_swap.c \
	so_sort_utils.c \
	so_greedy_sort.c \
	so_find_index.c \
	so_find_index_utils.c \

BONUS_SRCS = checker_bonus.c \
	checker_bonus_utils.c \
	get_next_line.c \
	get_next_line_utils.c \
	push_swap_utils.c \
	ps_param_utils.c \
	ps_deque_utils.c \
	ps_list_utils.c \
	op_push.c \
	op_rotate.c \
	op_reverse_rotate.c \
	op_swap.c \
	so_sort_utils.c \
	so_greedy_sort.c \
	so_find_index.c \
	so_find_index_utils.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME) $(BONUS)

bonus: $(BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re: fclean
	$(MAKE) all

.PHONY : all bonus clean fclean re
