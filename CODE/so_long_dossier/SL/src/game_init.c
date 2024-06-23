/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:08:54 by moni              #+#    #+#             */
/*   Updated: 2024/06/23 19:04:06 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Initialisation des structures et des composants du jeu. */
#include "../includes/so_long.h"

t_map	*game_init(char *mapname, t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 1920, 1850, mapname);
	map->img = mlx_xpm_file_to_image(map->img, "./flowers.xpm", 0, 0);
	// mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	mlx_hook(map->win, 2, 1L<<0, close_win, map);
	mlx_loop(map->mlx);
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