NAME = boom
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./lib/mlx_LINUX -I./lib/libft
LIBFT_PATH = ./lib/libft
MLX_PATH = ./lib/mlx_LINUX
LIBFT = -L$(LIBFT_PATH) -lft
MLX = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lbsd

SRC = src/event_handler.c src/game_loop.c src/map_loader.c src/render.c \
	src/utility.c src/game_init.c src/main.c src/memory_management.c \
	src/textures.c
OBJS = $(SRC:.c=.o)
HEADERS = -Iincludes

all: $(NAME)
#macOS	gcc $(OBJS) -o so_long -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJS)
	make -C ./lib/libft
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIBFT) $(MLX)

$(OBJS): %.o : %.c
	$(CC) $(CFLAGS) $(HEADERS)-I$(LIBFT_PATH) -I$(MLX_PATH) -c $< -o $@

clean:
	make -C ./lib/libft clean
	make -C ./lib/mlx_LINUX
	rm -f $(OBJS)

fclean: clean
	make -C ./lib/libft fclean
	make -C ./lib/mlx_LINUX
	rm -f $(NAME)

re: fclean all