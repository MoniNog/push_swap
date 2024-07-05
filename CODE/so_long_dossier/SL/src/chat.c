#include "../includes/so_long.h"

#define MAX_WIDTH 100

int close_window(void *param)
{
	(void)param;
	exit(0);
}

int handle_keypress(int keycode, void *param)
{
	t_game *game;
	game = (t_game *)param;

	if (keycode == KEY_UP)
		move_player(game, UP);
	else if (keycode == KEY_DOWN)
		move_player(game, DOWN);
	else if (keycode == KEY_LEFT)
		move_player(game, LEFT);
	else if (keycode == KEY_RIGHT)
		move_player(game, RIGHT);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

void *select_image(int map_value, t_game *game)
{
	if (map_value == 1)
		return game->img_wall;
	else if (map_value == 0)
		return game->img_floor;
	else if (map_value == 'C')
		return game->img_collectible;
	return NULL;
}

void draw_map(t_game *game, int map[MAX_WIDTH][MAX_WIDTH], int rows, int cols)
{
	int i;
	int j;
	void *img;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			img = select_image(map[i][j], game);
			if (img != NULL)
			{
				x = j * TILE_SIZE;
				y = i * TILE_SIZE;
				mlx_put_image_to_window(game->mlx, game->win, img, x, y);
			}
		j++;
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_game	game;
	int		img_width;
	int		img_height;
	void	*img;
	char	**map;

	if (argc != 2)
		return EXIT_FAILURE;
	if (argv[1][ft_strlen - 3] != '.' && argv[1][ft_strlen - 2] != 'b' && 
		argv[1][ft_strlen - 1] != 'e' && argv[1][ft_strlen] != 'r');

	map = ft_get_map(argv[1])
	game.mlx = mlx_init();
	if (!game.mlx)
		return EXIT_FAILURE;
	game.win = mlx_new_window(game.mlx, 1800, 1600, "so_long");
	if (!game.win)
		return EXIT_FAILURE;
	img = mlx_xpm_file_to_image(mlx, "IMG_XPM/chat.xpm", &img_width, &img_height);
	if (!img)
		return EXIT_FAILURE;
	mlx_put_image_to_window(game.mlx, game.win, img, 0, 0);
	mlx_hook(game.win, 2, 1L<<0, handle_keypress, &game);
	mlx_hook(game.win, 17, 1L<<0, close_window, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	return EXIT_SUCCESS;
}