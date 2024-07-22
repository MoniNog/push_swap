/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:08:54 by moni              #+#    #+#             */
/*   Updated: 2024/07/22 14:44:08 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Initialisation des structures et des composants du jeu. */
#include "../includes/so_long.h"

void	game_init(char *mapname, t_map *map)
{
	map->mouvement = 0;
	map->mlx = mlx_init();
	mlx_get_screen_size(map->mlx, &map->win_width, &map->win_height);
	map->win = mlx_new_window(map->mlx, map->win_width, map->win_height, mapname);
	map->img = malloc(sizeof(t_img));
	map->img->tree = mlx_xpm_file_to_image(map->mlx, "./img/tree.xpm", &map->img->img_width, &map->img->img_height);
	map->img->girl = mlx_xpm_file_to_image(map->mlx, "./img/girl.xpm", &map->img->img_width, &map->img->img_height);
	map->img->grass = mlx_xpm_file_to_image(map->mlx, "./img/grass.xpm", &map->img->img_width, &map->img->img_height);
	map->img->flower = mlx_xpm_file_to_image(map->mlx, "./img/fraise.xpm", &map->img->img_width, &map->img->img_height);
	map->img->basket = mlx_xpm_file_to_image(map->mlx, "./img/panier.xpm", &map->img->img_width, &map->img->img_height);
	map->img->win_game = mlx_xpm_file_to_image(map->mlx, "./img/win_game.xpm", &map->win_width, &map->win_height);
	draw_map(map);
	mlx_hook(map->win, 2, 1L<<0, handle_keypress, map);
	mlx_hook(map->win, 17, 0, close_win, &map);
	mlx_loop(map->mlx);

}

void	victory(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img->win_game, 0, 0);
	ft_printf("Nombre de deplacement : %i\n", map->mouvement);
	
}



// ft_init_smap: Initialise la structure de données du jeu.
// ft_init_mlx: Initialise les composants de MiniLibX nécessaires au rendu.
// init_map_struct: Initialise la structure de la carte.
// init_data_ending: Initialise les données de fin de jeu.
// init_sprites: Charge et initialise les sprites du jeu.
// init_player, init_player_2, init_player_inventory, init_player_collision: Fonctions pour initialiser les différents aspects du joueur.
