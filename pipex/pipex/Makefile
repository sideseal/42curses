# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 22:46:09 by gychoi            #+#    #+#              #
#    Updated: 2023/01/27 21:23:16 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -MMD -O2
RM = rm
RMFLAGS = -rf

LFTDIR = ./libft/
LFTLIB = -L./libft -lft
LIBFT = $(LFTDIR)libft.a

SRCS = pipex.c \
	   pipex_utils.c

BLDDIR = ./build/
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJECT = $(addprefix $(BLDDIR), $(OBJS))
DEPS = $(OBJECT:.o=.d)

$(NAME): $(BLDDIR) $(OBJECT) | $(LIBFT)
	$(CC) $(CFLAGS) $(LFTLIB) $(OBJECT) -o $@

$(BLDDIR)%.o: %.c
	$(CC) $(CLFAGS) $(DFLAGS) -c $< -o $@ -MMD

$(BLDDIR):
	@mkdir -p $(BLDDIR)

$(LIBFT):
	@$(MAKE) -C $(LFTDIR)

-include $(DEPS)

all: $(NAME)

clean:
	$(MAKE) -C $(LFTDIR) clean
	$(RM) $(RMFLAGS) $(BLDDIR)

fclean: clean
	$(RM) $(RMFLAGS) $(LIBFT)
	$(RM) $(RMFLAGS) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
