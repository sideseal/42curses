# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 17:33:02 by gychoi            #+#    #+#              #
#    Updated: 2022/12/10 19:09:45 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS =
MLXLIB = -L./mlx -lmlx -framework OpenGL -framework AppKit -Imlx
MLXDIR = ./mlx/
RM = rm -f

SRCS = main.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) $(MLXLIB) $^ -o $@
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

all: $(NAME)

clean:
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
