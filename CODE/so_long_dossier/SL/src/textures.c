/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:38 by moni              #+#    #+#             */
/*   Updated: 2024/06/21 10:49:45 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Chargement et gestion des textures du jeu. */
#include "../includes/so_long.h"

// void *select_img(int map_value, t_game *game)
// {
// 	if (map_value == 1)
// 		return game->img_wall;
// 	else if (map_value == 0)
// 		return game->img_floor;
// 	else if (map_value == 'C')
// 		return game->img_collectible;
// 	return NULL;
// }
// // set_img: Charge les textures utilisées dans le jeu.

// #include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

