# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 17:29:17 by gychoi            #+#    #+#              #
#    Updated: 2023/05/12 18:12:23 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pracRT
CC = cc
CFLAGS = -O2 -g
DFLAGS = -MMD
RM = rm -rf

MLXDIR = ./mlx/
MLXLIB = -L./mlx -lmlx -framework OpenGL -framework AppKit -Imlx
MLX = $(MLXDIR)libmlx.a

LFTDIR = ./libft/
LFTLIB = -L./libft -lft
LIBFT = $(LFTDIR)libft.a

LVCDIR = ./libvec/
LVCLIB = -L./libvec -lvec
LIBVEC = $(LVCDIR)libvec.a

SRCS = pracrt.c \
	   object.c \
	   ray.c \
	   hit.c \

OBJDIR = ./objs/
OBJS = $(addprefix $(OBJDIR), $(patsubst %.c, %.o, $(SRCS)))
DEPS = $(OBJS:.o=.d)

INCLUDE = -I./ -I$(LFTDIR) -I$(LVCDIR) -I$(MLXDIR)

$(NAME): $(OBJS) | $(LIBFT) $(LIBVEC) $(MLX)
	$(CC) $(CFLAGS) $(MLXLIB) $(LFTLIB) $(LVCLIB) $(INCLUDE) $(OBJS) -o $@
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

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
