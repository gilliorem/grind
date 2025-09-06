NAME = todo
DIR = src
INCLUDES = include
CC = gcc
CFLAGS = -g
SRCS = $(DIR)/handle_task.c gnl/get_next_line.c gnl/get_next_line_utils.c \
		$(DIR)/ledger.c lib/ft_itoa.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g3 -O0 -DDEBUG
debug: re

# Petit raccourci pratique pour lancer le binaire
run: $(NAME)
	./$(NAME)
