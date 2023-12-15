# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 22:46:41 by gychoi            #+#    #+#              #
#    Updated: 2023/11/27 16:24:57 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CXX = c++
CXXFLAGS = -std=c++98 -MD
CXXFLAGS += -Wall -Wextra -Werror -Wpedantic
CXXFLAGS += -I.
RM = rm -rf

SRCS = main.cpp \
	   Bureaucrat.cpp \
	   Form.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

ifdef DEBUG
	CXXFLAGS += -O1 -g -fsanitize=address,undefined, -fno-omit-frame-pointer
endif

%.o: %.cpp
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

$(NAME): $(OBJS)
	$(LINK.cpp) $^ $(LOADLIBS) $(LDLIBS) $(OUTPUT_OPTION)

-include $(DEPS)

.PHONY: all debug clean fclean re

all: $(NAME)

.NOTPARALLEL: debug
debug: fclean
	$(MAKE) DEBUG=1
	export MallocNanoZone=0 && ./a.out

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
