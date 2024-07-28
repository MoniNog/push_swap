/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:08:54 by moni              #+#    #+#             */
/*   Updated: 2024/07/28 14:29:07 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Initialisation des structures et des composants du jeu. */
#include "../includes/so_long.h"

void	game_init(char *mapname, t_map *map)
{
	map->game_over = 0;
	map->mouvement = 0;
	map->mlx = mlx_init();
	mlx_get_screen_size(map->mlx, &map->win_width, &map->win_height);
	map->win = mlx_new_window(map->mlx, map->win_width,
			map->win_height, mapname);
	map->i = malloc(sizeof(t_i));
	map->i->t = mlx_xpm_file_to_image(map->mlx, "./img/tree.xpm",
			&map->i->img_width, &map->i->img_height);
	map->i->p = mlx_xpm_file_to_image(map->mlx, "./img/girl.xpm",
			&map->i->img_width, &map->i->img_height);
	map->i->g = mlx_xpm_file_to_image(map->mlx, "./img/grass.xpm",
			&map->i->img_width, &map->i->img_height);
	map->i->c = mlx_xpm_file_to_image(map->mlx, "./img/fraise.xpm",
			&map->i->img_width, &map->i->img_height);
	map->i->e = mlx_xpm_file_to_image(map->mlx, "./img/panier.xpm",
			&map->i->img_width, &map->i->img_height);
	map->i->win_game = mlx_xpm_file_to_image(map->mlx, "./img/win_game.xpm",
			&map->win_width, &map->win_height);
	draw_map(map, 0);
	mlx_hook(map->win, 2, 1L << 0, handle_keypress, map);
	mlx_hook(map->win, 17, 0, close_win, &map);
	mlx_loop(map->mlx);
}

void	victory(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->i->win_game, 0, 0);
	map->game_over = 1;
}
