NAME = liblied #change my name!

CFLAGS = -Wall -Wextra -fanalyzer -std=c18
# LDFLAGS =

SRCDIR = ./
OBJDIR = ./build
INCDIR = $(SRCDIR)
SRCS = affine.c \
	cesar.c \
	polybiusD.c \
	vigenere.c \
	atbash.c \
	freq.c \
	polybiusC.c \
	substitution.c

CC = gcc
# if clang use -Weverything
ifeq ($(DEBUG),yes)
	CFLAGS += -ggdb -g3
else
	CFLAGS += -O3 # release mod optionnal compiler flags
endif
# linking flags

LD = $(CC)

OBJS = $(SRCS:.c=.o)
OBJS_PREF = $(addprefix $(OBJDIR)/, $(OBJS))


all: $(NAME)
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJS_PREF)
	#$(LD) -o $@ $^ $(LDFLAGS) -I$(INCDIR)
	ar -cvq $@.a $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCDIR)

clean:
	rm -f $(OBJS_PREF)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
