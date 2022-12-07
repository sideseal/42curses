# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 18:22:25 by gychoi            #+#    #+#              #
#    Updated: 2022/09/13 13:30:59 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crus
RM = rm -f

SRCS = ft_printf.c\
       print_address.c\
       print_char.c\
       print_number.c\
       print_string.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

.PHONY : all
all : $(NAME)

.PHONY : clean
clean :
	$(RM) $(OBJS)

.PHONY : fclean
fclean : clean
	$(RM) $(NAME)

.PHONY : re
re : fclean
	$(MAKE) all
