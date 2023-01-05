# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 17:33:02 by gychoi            #+#    #+#              #
#    Updated: 2023/01/05 18:33:29 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
RMFLAGS = -r

MLXDIR = ./mlx/
MLXLIB = -L./mlx -lmlx -framework OpenGL -framework AppKit -Imlx
MLX = $(MLXDIR)libmlx.a

LFTDIR = ./libft/
LFTLIB = -L./libft -lft
LIBFT = $(LFTDIR)libft.a

HDRDIR = ./includes/
HDRS = fdf.h \
	   fdf_bonus.h
HEADERS = $(addprefix $(HDRDIR), $(HDRS))
INCLUDES = -I$(HDRDIR) -I$(LFTDIR) -I$(MLXDIR)

SRCDIR = ./srcs/
SRCS = main.c \
       init1.c \
       init2.c \
       set.c \
       utils1.c \
       utils2.c \
       read.c \
       draw.c \
       hooks.c \
       rotate.c \
       project.c
SOURCES = $(addprefix $(SRCDIR), $(SRCS))

BNSDIR = ./bonus/
BONUS = main_bonus.c \
       init1_bonus.c \
       init2_bonus.c \
       set_bonus.c \
       utils1_bonus.c \
       utils2_bonus.c \
       read_bonus.c \
       draw_bonus.c \
       hooks_bonus.c \
       rotate_bonus.c \
       project_bonus.c
BONUSES = $(addprefix $(BNSDIR), $(BONUS))

OBJDIR = ./objs/
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJECTS = $(addprefix $(OBJDIR), $(OBJS))

BOBJDIR = ./bobjs/
BNSOBJ = $(patsubst %.c, %.o, $(BONUS))
BNSOBJS = $(addprefix $(BOBJDIR), $(BNSOBJ))

ifdef WITH_BONUS
	COMPOBJS = $(BNSOBJS)
	COMPSDIR = $(BNSDIR)
	COMPODIR = $(BOBJDIR)
else
	COMPOBJS = $(OBJECTS)
	COMPSDIR = $(SRCDIR)
	COMPODIR = $(OBJDIR)
endif

all:
	@$(RM) $(RMFLAGS) $(BOBJDIR)
	@$(MAKE) $(NAME)

bonus:
	@$(RM) $(RMFLAGS) $(OBJDIR)
	@$(MAKE) $(NAME) WITH_BONUS=1

$(NAME): $(COMPOBJS) | $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(MLXLIB) $(LFTLIB) $(INCLUDES) $(COMPOBJS) -o $@
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

$(COMPODIR)%.o: $(COMPSDIR)%.c
	@mkdir -p $(COMPODIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LFTDIR)

$(MLX):
	@$(MAKE) -C $(MLXDIR)

clean:
	$(MAKE) -C $(MLXDIR) clean
	$(MAKE) -C $(LFTDIR) clean
	$(RM) $(RMFLAGS) $(OBJDIR)
	$(RM) $(RMFLAGS) $(BOBJDIR)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(MLX)
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re
