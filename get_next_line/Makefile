#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 14:53:29 by gychoi            #+#    #+#              #
#    Updated: 2022/08/18 16:23:39 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

TARGET = gnl.out

SRCS_NAME = get_next_line.c get_next_line_utils.c main.c
SRCS_DIR = project
TEST_DIR = test
SRCS := $(wildcard $(TEST_DIR)/*.c) $(wildcard $(SRCS_DIR)/*.c)
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS_DIR = .
OBJS := $(patsubst %.o,$(OBJS_DIR)/%.o,$(OBJS_NAME))

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : all
all : $(TARGET)

.PHONY : clean
clean :
	$(RM) $(OBJS)

.PHONY : fclean
fclean : clean
	$(RM) $(TARGET)

.PHONY : re
re : fclean
	$(MAKE) all
