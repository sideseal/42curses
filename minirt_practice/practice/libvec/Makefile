# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 21:03:28 by gychoi            #+#    #+#              #
#    Updated: 2023/05/11 21:07:33 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvec.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crus
RM = rm -rf

SRCS = vadd.c \
	   vadds.c \
	   vcross.c \
	   vdivs.c \
	   vdot.c \
	   vec3.c \
	   vlen.c \
	   vmax.c \
	   vmin.c \
	   vmult.c \
	   vmults.c \
	   vset.c \
	   vsub.c \
	   vsubs.c \
	   vunit.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

.PHONY: all clean flclean re

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	@make all
