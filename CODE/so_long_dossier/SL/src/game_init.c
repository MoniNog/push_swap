/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:08:54 by moni              #+#    #+#             */
/*   Updated: 2024/07/05 18:47:32 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Initialisation des structures et des composants du jeu. */
#include "../includes/so_long.h"

t_map	*game_init(char *mapname, t_map *map)
{
	int 	img_width;
	int		img_height;

	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 1920, 1850, mapname);
	map->img = malloc(sizeof(t_img));
	map->img->tree = mlx_xpm_file_to_image(map->mlx, "./img/tree.xpm", &img_width, &img_height);
	map->img->girl = mlx_xpm_file_to_image(map->mlx, "./img/girl.xpm", &img_width, &img_height);
	map->img->grass = mlx_xpm_file_to_image(map->mlx, "./img/grass.xpm", &img_width, &img_height);
	map->img->flower = mlx_xpm_file_to_image(map->mlx, "./img/flower.xpm", &img_width, &img_height);
	map->img->basket = mlx_xpm_file_to_image(map->mlx, "./img/basket.xpm", &img_width, &img_height);

	draw_map(map->array);

	// mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	mlx_hook(map->win, 2, 1L<<0, handle_keypress, map);
	mlx_loop(map->mlx);
}

void	draw_map(t_map *map)
{
	int		x;
	int		y;
	int 	img_width;
	int		img_height;

	y = 0;
	while(y < map->height )
	{
		x = 0;
		while(x < map->width )
		{
			if(map->array[y][x] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->img->tree, x * img_width, y * img_height);
			if(map->array[y][x] == '0')
				mlx_put_image_to_window(map->mlx, map->win, map->img->grass, x * img_width, y * img_height);
			if(map->array[y][x] == 'P')
				mlx_put_image_to_window(map->mlx, map->win, map->img->girl, x * img_width, y * img_height);
			if(map->array[y][x] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->img->basket, x * img_width, y * img_height);
			if(map->array[y][x] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->img->flower, x * img_width, y * img_height);
			x++;
		}
		y++;
	}
}

// ft_init_smap: Initialise la structure de données du jeu.
// ft_init_mlx: Initialise les composants de MiniLibX nécessaires au rendu.
// init_map_struct: Initialise la structure de la carte.
// init_data_ending: Initialise les données de fin de jeu.
// init_sprites: Charge et initialise les sprites du jeu.
// init_player, init_player_2, init_player_inventory, init_player_collision: Fonctions pour initialiser les différents aspects du joueur.

//			ELISE :
	// map.render// variable de type t_map
	// map->render// pointeur vers render (path)

	// y = 0;
	// while(y <= map->height)
	// {
	// 	x = 0
	// 	while(x <= map->width)
	// 	{
	// 		x++;
	// 	}
	// 	y++;
	// }