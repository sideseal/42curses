# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 17:30:49 by salee2            #+#    #+#              #
#    Updated: 2023/05/31 17:30:53 by salee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
MLXDIR		= ./minilibx_opengl_20191021
MLXFILE		= libmlx.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit -lz

SRCS = \
	camera.c \
	canvas.c \
	clamp.c \
	color.c \
	cone.c \
	cone_base.c \
	cone_surfcae.c \
	cylinder.c \
	cylinder_base.c \
	cylinder_surface.c \
	diffuse.c \
	hit.c \
	keyboard.c \
	light.c \
	main.c \
	free.c \
	objects.c \
	phong_lighting.c \
	plane.c \
	ray.c \
	raytracer.c \
	render.c \
	scene.c \
	specular.c \
	sphere.c \
	vector.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(MLXFLAGS) $(MLXDIR)/$(MLXFILE)

%o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(MLXDIR) clean
	$(RM) $(OBJS) $(MLXFILE)

fclean: clean
	make -C $(MLXDIR) clean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
