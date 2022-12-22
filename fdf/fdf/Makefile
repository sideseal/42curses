# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 17:33:02 by gychoi            #+#    #+#              #
#    Updated: 2022/12/22 17:36:47 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g
MLXLIB = -L./mlx -lmlx -framework OpenGL -framework AppKit -Imlx
MLXDIR = ./mlx/
LFTDIR = ./libft/
SRCDIR = ./src/
RM = rm -f

SRCS = main.c \
       list.c \
       init.c \
       utils.c \
       read.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LFTDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) $(MLXLIB) $^ -o $@ -L./libft -lft
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

$(LIBFT):
	$(MAKE) -C $(LFTDIR)

$(MLX):
	$(MAKE) -C $(MLXDIR)

all: $(NAME)

clean:
	$(MAKE) -C $(MLXDIR) clean
	$(MAKE) -C $(LFTDIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
