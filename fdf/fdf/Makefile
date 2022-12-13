# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 17:33:02 by gychoi            #+#    #+#              #
#    Updated: 2022/12/13 20:34:46 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g
MLXLIB = -L./mlx -lmlx -framework OpenGL -framework AppKit -Imlx
MLXDIR = ./mlx/
LIBFT = ./libft/
RM = rm -f

SRCS = main.c \
	   proc_file.c \
	   util_fdf.c \
	   util_init.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(MLXDIR)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(MLXLIB) $^ -o $@ -L./libft -lft
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

all: $(NAME)

clean:
	$(MAKE) -C $(MLXDIR) clean
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
