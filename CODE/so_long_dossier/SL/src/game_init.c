/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:08:54 by moni              #+#    #+#             */
/*   Updated: 2024/06/21 12:06:16 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Initialisation des structures et des composants du jeu. */
#include "../includes/so_long.h"

t_map	*game_init(char *mapname, t_map *map)	// OUTPUT : renvoie ptr vers notre jeu 
									// INPUT nom du fichier map (ex : map1.ber)
{
	//void	*img;
	// int		keycode;
	
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 1920, 1850, mapname);
	map->render = malloc(sizeof(t_render));
	map->render->img = mlx_new_image(map->mlx, 1920, 1050);
	// mlx_pixel_put(map->mlx, map->win, 100, 100, 0x0FAE3);
	
	map->render->addr = mlx_get_data_addr(map->render->img, map->render->bits_per_pixel, &map->render->line_length, &map->render->endian);
	//mlx_put_image_to_window(map->mlx, map->win, map->render->img, 0, 0);
	mlx_hook(map->win, 2, 1L<<0, close_win, map);
	mlx_loop(map->mlx);

	
}

void	my_mlx_pixel_put(t_render *render, int x, int y, int color)
{
	char	*dst;

	dst = render->addr + (y * render->line_length + x * (render->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// ft_init_smap: Initialise la structure de données du jeu.
// ft_init_mlx: Initialise les composants de MiniLibX nécessaires au rendu.
// init_map_struct: Initialise la structure de la carte.
// init_data_ending: Initialise les données de fin de jeu.
// init_sprites: Charge et initialise les sprites du jeu.
// init_player, init_player_2, init_player_inventory, init_player_collision: Fonctions pour initialiser les différents aspects du joueur.


	// map.render// variable de type t_map
	// map->render// pointeur vers render (path)