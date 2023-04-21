# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 18:12:34 by gychoi            #+#    #+#              #
#    Updated: 2023/04/21 19:25:35 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ifdef CHECK_TSAN
	CFLAGS += -fsanitize=thread -g
endif
DFLAGS = -MMD
RM = rm
RMFLAGS = -rf
PTHREAD = -pthread
BLDDIR = ./objs/

SRCS = main.c \
	   init.c \
	   clear.c \
	   utils.c \
	   validate.c \
	   simulate.c

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

check: fclean
	@make $(NAME) CHECK_TSAN=1

clean:
	$(RM) $(RMFLAGS) $(BLDDIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean
	$(MAKE) all
