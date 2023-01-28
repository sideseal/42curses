# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 22:46:09 by gychoi            #+#    #+#              #
#    Updated: 2023/01/29 01:03:35 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
DFLAGS = -MMD

RM = rm
RMFLAGS = -rf

LFTDIR = ../libft/
BLDDIR = ../build/

LIBFT = $(LFTDIR)libft.a
LFTLIB = -L$(LFTDIR) -lft

SRCS = pipex.c \
	   pipex_utils.c

OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJECT = $(addprefix $(BLDDIR), $(OBJS))
DEPS = $(OBJECT:.o=.d)

$(NAME): $(OBJECT) | $(LIBFT)
	$(CC) $(CFLAGS) $(LFTLIB) $(OBJECT) -o $@

$(BLDDIR)%.o: %.c
	$(CC) $(CLFAGS) $(DFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LFTDIR)

-include $(DEPS)

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(BLDDIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
