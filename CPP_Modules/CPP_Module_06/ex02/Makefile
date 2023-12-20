# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 20:52:01 by gychoi            #+#    #+#              #
#    Updated: 2023/12/20 23:15:41 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CXX = c++
CXXFLAGS = -std=c++98 -MD
CXXFLAGS += -Wall -Wextra -Werror -Wpedantic
CXXFLAGS += -I.
RM = rm -rf

SRCS = main.cpp \
	   Base.cpp \
	   A.cpp \
	   B.cpp \
	   C.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

%.o: %.cpp
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

$(NAME): $(OBJS)
	$(LINK.cpp) $^ $(LOADLIBS) $(LDLIBS) $(OUTPUT_OPTION)

-include $(DEPS)

.PHONY: all debug clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
