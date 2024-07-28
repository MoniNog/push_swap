/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:34 by moni              #+#    #+#             */
/*   Updated: 2024/07/28 16:46:42 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Gestion de tout le rendu graphique du jeu. */
#include "../includes/so_long.h"

void	draw_map(t_map *m, int y)
{
	int		x;
	int		w;
	int		h;

	w = m->i->img_width;
	h = m->i->img_height;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			if (m->array[y][x] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->i->t, x * w, y * h);
			if (m->array[y][x] == '0')
				mlx_put_image_to_window(m->mlx, m->win, m->i->g, x * w, y * h);
			if (m->array[y][x] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, m->i->p, x * w, y * h);
			if (m->array[y][x] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->i->e, x * w, y * h);
			if (m->array[y][x] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->i->c, x * w, y * h);
			x++;
		}
		y++;
	}
}
