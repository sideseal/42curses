# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 22:46:09 by gychoi            #+#    #+#              #
#    Updated: 2023/01/17 23:22:35 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf

LFTDIR = ./libft/
LFTLIB = -L./libft -lft
LIBFT = $(LFTDIR)libft.a

SRCS = pipex.c \
	   pipex_utils.c

OBJDIR = ./objs/
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJECT = $(addprefix $(OBJDIR), $(OBJS))

$(NAME): $(OBJECT) | $(LIBFT)
	$(CC) $(CFLAGS) $(LFTLIB) $(OBJECT) -o $@

$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CLFAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LFTDIR)

all: $(NAME)

clean:
	$(MAKE) -C $(LFTDIR) clean
	$(RM) $(RMFLAGS) $(OBJDIR)

fclean: clean
	$(RM) $(RMFLAGS) $(LIBFT)
	$(RM) $(RMFLAGS) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
