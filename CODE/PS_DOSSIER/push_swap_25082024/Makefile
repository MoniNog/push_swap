NAME = push_swap
CC = gcc
CFLAGS =  -Wall -Wextra -g3 -fsanitize=address -I./lib/libft -Wno-unused-parameter
# CFLAGS =  -Wall -Wextra -I./lib/libft -Wno-unused-parameter
LIBFT_PATH = ./lib/libft
LIBFT = -L$(LIBFT_PATH) -lft

SRC = src/sort/algo.c src/main.c src/fun/push.c src/fun/reverse_rotate.c src/fun/rotate.c\
	src/fun/swap.c src/fun/utils_stack.c src/memory_management.c 
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
