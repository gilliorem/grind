NAME = grind
CC = gcc
CFLAGS = -g
SRC_DIR = src
SRCS = handle_task.c ledger.c parser.c cmd.c quest.c file.c main.c

OBJS = $(addprefix $(SRC_DIR)/,$(SRCS:.c=.o))
INCLUDES =  -Iinclude -Ilibft
READLINE = -lreadline
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
