/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:34 by moni              #+#    #+#             */
/*   Updated: 2024/07/22 14:22:52 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Gestion de tout le rendu graphique du jeu. */
 #include "../includes/so_long.h"

void	draw_map(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while(y < map->height)
	{
		x = 0;
		while(x < map->width)
		{
			if(map->array[y][x] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->img->tree, x * map->img->img_width, y * map->img->img_height);
			if(map->array[y][x] == '0')
				mlx_put_image_to_window(map->mlx, map->win, map->img->grass, x * map->img->img_width, y * map->img->img_height);
			if(map->array[y][x] == 'P')
				mlx_put_image_to_window(map->mlx, map->win, map->img->girl, x * map->img->img_width, y * map->img->img_height);
			if(map->array[y][x] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->img->basket, x * map->img->img_width, y * map->img->img_height);
			if(map->array[y][x] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->img->flower, x * map->img->img_width, y * map->img->img_height);
			x++;
		}
		y++;
	}
}

// mlx_put_image_to_window
// ft_render, render, core_render, render_other, render_background, render_down,
// render_left, render_right, render_top, draw, draw_background, draw_hud, draw_hud_life,
// draw_hud_mana, draw_hud_steps: Toutes les fonctions liées au rendu des différents composants à l'écran.