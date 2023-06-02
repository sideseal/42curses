# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 16:27:39 by gychoi            #+#    #+#              #
#    Updated: 2023/06/02 21:16:54 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

LIBDIR = libs/
MLXDIR = $(LIBDIR)minilibx_opengl_20191021/
LFTDIR = $(LIBDIR)libft/
LVCDIR = $(LIBDIR)libvec/

CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
DFLAGS = -MMD -MP -g
CPPFLAGS = -Iinclude/ -I$(LFTDIR) -I$(MLXDIR) -I$(LVCDIR)
LDFLAGS = -L$(MLXDIR) -L$(LFTDIR) -L$(LVCDIR)
LDLIBS = -lmlx -lft -lvec
MLXFLAGS = -framework OpenGL -framework AppKit
RM = rm -rf

MLX = $(MLXDIR)libmlx.a
LIBFT = $(LFTDIR)libft.a
LIBVEC = $(LVCDIR)libvec.a

SRCDIR = src/
SOURCE = check.c \
		 free.c \
		 hook.c \
		 init.c \
		 main.c \
		 read.c \
		 redef_libf.c \
		 redef_mlx.c \
		 render.c \
		 set.c \

SRCS = $(addprefix $(SRCDIR), $(SOURCE))

OBJDIR = build/
OBJECT = $(patsubst %.c, %.o, $(SOURCE))
OBJS = $(addprefix $(OBJDIR), $(OBJECT))
DEPS = $(OBJS:.o=.d)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(COMPILE.c) $(DFLAGS) $(OUTPUT_OPTION) $<

$(NAME): $(OBJS) $(LIBFT) $(LIBVEC) $(MLX)
	$(LINK.o) $^ $(LDLIBS) $(MLXFLAGS) -o $@
	@install_name_tool -change libmlx.dylib $(MLXDIR)libmlx.dylib $(NAME)

$(LIBFT): .FORCE
	$(MAKE) -C $(LFTDIR)

$(LIBVEC): .FORCE
	$(MAKE) -C $(LVCDIR)

$(MLX): .FORCE
	$(MAKE) -C $(MLXDIR)

.FORCE:

-include $(DEPS)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(MAKE) -C $(LFTDIR) clean
	$(MAKE) -C $(LVCDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(LIBVEC)
	$(RM) $(MLX)
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
