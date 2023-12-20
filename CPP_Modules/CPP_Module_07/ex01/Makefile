# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 20:52:01 by gychoi            #+#    #+#              #
#    Updated: 2023/12/21 00:01:51 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CXX = c++
CXXFLAGS = -std=c++98 -MD
CXXFLAGS += -Wall -Wextra -Werror -Wpedantic -Wshadow
CXXFLAGS += -I.
RM = rm -rf

SRCS = main.cpp
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
