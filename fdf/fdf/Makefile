# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 17:33:02 by gychoi            #+#    #+#              #
#    Updated: 2023/01/01 20:09:21 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
#CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -g
RM = rm -f
RMFLAGS = -r

MLXDIR = ./mlx/
MLXLIB = -L./mlx -lmlx -framework OpenGL -framework AppKit -Imlx
MLX = $(MLXDIR)libmlx.a

LFTDIR = ./libft/
LFTLIB = -L./libft -lft
LIBFT = $(LFTDIR)libft.a

SRCDIR = ./srcs/
SRCS = main.c \
       init1.c \
       init2.c \
       set.c \
       utils.c \
       read.c \
       draw.c \
       hooks.c \
       rotate.c \
       project.c \

SOURCES = $(addprefix $(SRCDIR), $(SRCS))

OBJDIR = ./objs/
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJECTS = $(addprefix $(OBJDIR), $(OBJS))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LFTDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) $(MLXLIB) $(LFTLIB) $(OBJECTS) -o $@
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(MLXDIR) clean
	$(MAKE) -C $(LFTDIR) clean
	$(RM) $(RMFLAGS) $(OBJDIR)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(MLX)
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
