# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 18:12:34 by gychoi            #+#    #+#              #
#    Updated: 2023/04/21 00:57:26 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -fsanitize=thread -g
DFLAGS = -MMD
RM = rm
RMFLAGS = -rf
PTHREAD = -pthread
BLDDIR = ./objs/

SRCS = main.c \
	   init.c \
	   clear.c \
	   utils.c \
	   simulate.c \

OBJS = $(addprefix $(BLDDIR), $(patsubst %.c, %.o, $(SRCS)))
DEPS = $(OBJS:.o=.d)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BLDDIR)%.o: %.c | $(BLDDIR)
	$(CC) $(CFLAGS) $(DFLAGS) $(PTHREAD) -c $< -o $@

$(BLDDIR):
	@mkdir -p $(BLDDIR)

-include $(DEPS)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(BLDDIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean
	$(MAKE) all
