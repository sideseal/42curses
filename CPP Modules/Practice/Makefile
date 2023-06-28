NAME = hello

NASM = nasm
LD = ld
NFLAGS = -f macho64 -O0
LFLAGS = -macosx_version_min 10.7.0
RM = rm -rf

SRCS = hello.s
OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LD) $(LFLAGS) $< -o $@

%.o: %.s
	$(NASM) $(NFLAGS) $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all


.PHONY: all clean fclean re
