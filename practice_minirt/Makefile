# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 17:29:17 by gychoi            #+#    #+#              #
#    Updated: 2023/05/04 17:54:10 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pracRT
CC = cc
CFLAGS = -g
DFLAGS = -MMD
RM = rm -rf

MLXDIR = ./mlx/
MLXLIB = -L./mlx -lmlx -framework OpenGL -framework AppKit -Imlx
MLX = $(MLXDIR)libmlx.a

SRCS = main.c \
	   draw.c \
	   hooks.c \
	   ray.c \
	   hit.c \
	   scene.c \
	   vector.c \
	   object.c \

OBJDIR = ./objs/
OBJS = $(addprefix $(OBJDIR), $(patsubst %.c, %.o, $(SRCS)))
DEPS = $(OBJS:.o=.d)

INCLUDE = -I$(MLXDIR)

$(NAME): $(OBJS) | $(MLX)
	$(CC) $(CFLAGS) $(MLXLIB) $(INCLUDE) $(OBJS) -o $@
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

$(OBJDIR)%.o: %.c  | $(OBJDIR)
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) -c $< -o $@

$(MLX):
	@make -C $(MLXDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

-include $(DEPS)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	@make -C $(MLXDIR) clean
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(MLX)
	$(RM) $(NAME)

re: fclean
	@make all
