# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 22:46:41 by gychoi            #+#    #+#              #
#    Updated: 2023/08/17 23:36:03 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS += -W -Wshadow -Wconversion -Wpedantic
CXXFLAGS += -std=c++98 -MMD -MP
CPPFLAGS = -I.
RM = rm -rf

SRCS = main.cpp \
	   AMateria.cpp \
	   Character.cpp \
	   Cure.cpp \
	   Ice.cpp \
	   MateriaSource.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

ifdef DEBUG
	CXXFLAGS += -g
else ifdef LEAKS
	CXXFLAGS += -DLEAKS_CHECK
endif

%.o: %.cpp
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

$(NAME): $(OBJS)
	$(LINK.cpp) $^ $(LOADLIBS) $(LDLIBS) $(OUTPUT_OPTION)

-include $(DEPS)

.PHONY: all debug clean fclean re

all: $(NAME)

debug: fclean
	$(MAKE) all DEBUG=1

leaks: fclean
	$(MAKE) all LEAKS=1

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
