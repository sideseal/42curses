# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 22:46:09 by gychoi            #+#    #+#              #
#    Updated: 2023/01/27 03:53:45 by gychoi           ###   ########.fr        #
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

BUILD_DIR = ./build/
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJECT = $(addprefix $(BUILD_DIR), $(OBJS))
DEPS = $(OBJECT:.o=.d)

$(NAME): $(BUILD_DIR) $(OBJECT) | $(LIBFT)
	$(CC) $(CFLAGS) $(LFTLIB) $(OBJECT) -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)%.o: %.c
	$(CC) $(CLFAGS) $(DFLAGS) -c $< -o $@ -MMD

-include $(DEPS)

$(LIBFT):
	@$(MAKE) -C $(LFTDIR)

all: $(NAME)

clean:
	$(MAKE) -C $(LFTDIR) clean
	$(RM) $(RMFLAGS) $(BUILD_DIR)

fclean: clean
	$(RM) $(RMFLAGS) $(LIBFT)
	$(RM) $(RMFLAGS) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
