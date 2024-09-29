NAME = push_swap
CC = gcc
CFLAGS =  -Wall -Wextra -I./lib/libft -Wno-unused-parameter
# CFLAGS =  -Wall -Wextra -g3 -fsanitize=address -I./lib/libft -Wno-unused-parameter
LIBFT_PATH = ./lib/libft
LIBFT = -L$(LIBFT_PATH) -lft

SRC = src/fun/push.c src/fun/rotate.c src/fun/reverse_rotate.c src/fun/swap.c\
		src/sort/sort.c src/sort/sort_3.c src/sort/sort_4.c src/sort/utils_sort.c\
		src/sort/utils_sort_2.c src/sort/sort_100_500.c\
		src/stack/create_stack.c src/stack/print_stack.c\
		src/memory_management.c src/main.c src/checkers.c src/split.c

OBJS = $(SRC:.c=.o)
HEADERS = -Iincludes

all: $(NAME)

$(NAME): $(OBJS) libft.a
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIBFT)

libft.a:
	@make -C $(LIBFT_PATH) --silent

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -I$(LIBFT_PATH) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean --silent
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean --silent
	@rm -f $(NAME)

re: fclean all
