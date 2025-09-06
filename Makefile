NAME = todo
DIR = src
INLCUDES = include
CC = gcc
CFLAGS = -g
SRCS = $(DIR)/handle_task.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) $(INCLUDES) -c $< -o $@

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
