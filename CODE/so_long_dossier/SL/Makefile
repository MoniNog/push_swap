NAME = so_long
CC = gcc
CFLAGS = -Wall -g3 -fsanitize=address -Wextra  -I./lib/mlx_LINUX -I./lib/libft -Werror
# CFLAGS = -Wall -Wextra  -I./lib/mlx_LINUX -I./lib/libft -Werror
LIBFT_PATH = ./lib/libft
MLX_PATH = ./lib/mlx_LINUX -lmlx
LIBFT = -L$(LIBFT_PATH) -lft
MLX = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lbsd -g

SRC = src/utility.c src/event_handler.c src/game_loop.c src/map_loader.c \
	src/render.c src/game_init.c src/main.c src/memory_management.c\
	src/checker.c\
	lib/libft/ft_lstnew.c lib/libft/ft_lstadd_front.c lib/libft/ft_lstmap.c\
	lib/libft/ft_lstsize.c lib/libft/ft_lstlast.c lib/libft/ft_lstadd_back.c\
	lib/libft/ft_lstdelone.c lib/libft/ft_lstclear.c lib/libft/ft_lstiter.c\
	lib/libft/ft_memcmpext.c
OBJS = $(SRC:.c=.o)
HEADERS = -Iincludes


all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH) > /dev/null 2>&1
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIBFT) $(MLX) > /dev/null 2>&1

@$(OBJS): %.o : %.c
	@$(CC) $(CFLAGS) $(HEADERS)-I$(LIBFT_PATH) -I$(MLX_PATH) -c $< -o $@  

clean:
	@make -C $(LIBFT_PATH) clean > /dev/null 2>&1
	@rm -f $(OBJS) > /dev/null 2>&1

fclean: clean
	@make -C $(LIBFT_PATH) fclean > /dev/null 2>&1
	@rm -f $(NAME) > /dev/null 2>&1

re: fclean all

#macOS	gcc $(OBJS) -o so_long -lmlx -framework OpenGL -framework AppKit


