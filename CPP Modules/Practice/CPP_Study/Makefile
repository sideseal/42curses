NAME = output
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
CXXFLAGS += -std=c++98 -MMD -MP
CPPFLAGS = -I.
RM = rm -rf

SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
-include $(DEPS)

ifdef DEBUG
	CXXFLAGS += -g
endif

all: $(NAME)

%.o: %.cpp
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

$(NAME): $(OBJS)
	$(LINK.cpp) $^ $(LOADLIBS) $(LDLIBS) -o $@

debug: fclean
	$(MAKE) all DEBUG=1

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
