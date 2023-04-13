# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 16:34:49 by gychoi            #+#    #+#              #
#    Updated: 2023/04/13 23:14:39 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
#CFLAGS = -fsanitize=thread -g
CFLAGS = -Wall -Wextra -Werror -O2
DFLAGS = -MMD
RM = rm
RMFLAGS = -rf
PTHREAD = -pthread
BLDDIR = ./build/

SRCS = main.c \
	   init.c \
	   clear.c \
	   philo.c \
	   utils.c \
	   routine.c \

OBJS = $(addprefix $(BLDDIR), $(patsubst %.c, %.o, $(SRCS)))
DEPS = $(OBJS:.o=.d)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BLDDIR)%.o: %.c | $(BLDDIR)
	$(CC) $(CFLAGS) $(DFLAGS) $(PTHREAD) -c $< -o $@

$(BLDDIR):
	@mkdir -p $(BLDDIR)

-include $(DEPS)

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(BLDDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
