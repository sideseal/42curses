# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 17:35:46 by gychoi            #+#    #+#              #
#    Updated: 2023/05/27 21:54:05 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Test
CC = cc
CFLAGS = -O3 -g -Wall -Wextra -Werror
DFLAGS = -MMD
RM = rm -rf

LIBDIR = libs/

MLXDIR = $(LIBDIR)mlx/
MLXLIB = -L$(LIBDIR)mlx -lmlx -framework OpenGL -framework AppKit -Imlx
MLX = $(MLXDIR)libmlx.a

LFTDIR = $(LIBDIR)libft/
LFTLIB = -L$(LIBDIR)libft -lft
LIBFT = $(LFTDIR)libft.a

LVCDIR = $(LIBDIR)libvec/
LVCLIB = -L$(LIBDIR)libvec -lvec
LIBVEC = $(LVCDIR)libvec.a

SRCS = camera.c \
	   draw.c \
	   hit.c \
	   hooks.c \
	   init.c \
	   object.c \
	   object_utils.c \
	   pracrt.c \
	   ray.c \
	   render.c \

OBJDIR = ./objs/
OBJS = $(addprefix $(OBJDIR), $(patsubst %.c, %.o, $(SRCS)))
DEPS = $(OBJS:.o=.d)

INCLUDE = -I./ -I$(LFTDIR) -I$(LVCDIR) -I$(MLXDIR)

$(NAME): $(OBJS) | $(LIBFT) $(LIBVEC) $(MLX)
	$(CC) $(CFLAGS) $(MLXLIB) $(LFTLIB) $(LVCLIB) $(INCLUDE) $(OBJS) -o $@
	@install_name_tool -change libmlx.dylib $(MLXDIR)libmlx.dylib $(NAME)

$(OBJDIR)%.o: %.c  | $(OBJDIR)
	$(CC) $(CFLAGS) $(DFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	@make -C $(LFTDIR)

$(LIBVEC):
	@make -C $(LVCDIR)

$(MLX):
	@make -C $(MLXDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

-include $(DEPS)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	@make -C $(LFTDIR) clean
	@make -C $(LVCDIR) clean
	@make -C $(MLXDIR) clean
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(LIBVEC)
	$(RM) $(MLX)
	$(RM) $(NAME)

re: fclean
	@make all
