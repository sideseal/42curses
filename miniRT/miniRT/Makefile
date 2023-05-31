# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 16:27:39 by gychoi            #+#    #+#              #
#    Updated: 2023/05/31 20:22:51 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

LIBDIR = libs/
MLXDIR = $(LIBDIR)minilibx_opengl_20191021/
LFTDIR = $(LIBDIR)libft/

CC = cc
CFLAGS = -Wall -Wextra -Werror -O2 -MMD -MP
CPPFLAGS = -Iinclude/ -I$(LFTDIR) -I$(MLXDIR)
LDFLAGS = -L$(MLXDIR) -L$(LFTDIR)
LDLIBS = -lmlx -lft
#MLXFLAGS = -framework OpenGL -framework AppKit

RM = rm -rf

MLX = $(MLXDIR)libmlx.a
LIBFT = $(LFTDIR)libft.a

SRCDIR = src/
SOURCE = main.c \

SRCS = $(addprefix $(SRCDIR), $(SOURCE))

OBJDIR = build/
OBJECT = $(patsubst %.c, %.o, $(SOURCE))
OBJS = $(addprefix $(OBJDIR), $(OBJECT))
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@
	@install_name_tool -change libmlx.dylib $(MLXDIR)libmlx.dylib $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT): .FORCE
	@make -C $(LFTDIR)

$(MLX): .FORCE
	@make -C $(MLXDIR)

.FORCE:

.PHONY: all clean fclean re

all: $(NAME)

clean:
	@make -C $(LFTDIR) clean
	@make -C $(MLXDIR) clean
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(MLX)
	$(RM) $(NAME)

re: fclean
	@make all
