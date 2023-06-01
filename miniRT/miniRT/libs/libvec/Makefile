# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 20:30:05 by gychoi            #+#    #+#              #
#    Updated: 2023/06/01 22:59:26 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -MMD -MP
ARFLAGS = crus
RM = rm -rf

SRCS = add.c \
	   color3_.c \
	   cross.c \
	   dot.c \
	   elem_max.c \
	   elem_min.c \
	   hadam_prod.c \
	   mag.c \
	   mag_sq.c \
	   norm.c \
	   point3_.c \
	   scl_add.c \
	   scl_div.c \
	   scl_mul.c \
	   scl_sub.c \
	   sub.c \
	   vec2_.c \
	   vec3_.c \

OBJS = $(SRCS:.c=.o)

DEPS = $(OBJS:.o=.d)

NAME = libvec.a

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

-include $(DEPS)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
