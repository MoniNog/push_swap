/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:31 by moni              #+#    #+#             */
/*   Updated: 2024/07/27 17:59:07 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Gestion de la libération de la mémoire pour différentes structures. */
#include "../includes/so_long.h"

void	free_array(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->array [i]);
		free(map->map_copy[i]);
		i++;
	}
	free(map->array);
	free(map->map_copy);
}

void	ft_free_all(t_map *map)
{
	ft_lstclear(&(map->lines), free);
	if (map->i)
	{
		if (map->i->t)
			mlx_destroy_image(map->mlx, map->i->t);
		if (map->i->g)
			mlx_destroy_image(map->mlx, map->i->g);
		if (map->i->p)
			mlx_destroy_image(map->mlx, map->i->p);
		if (map->i->c)
			mlx_destroy_image(map->mlx, map->i->c);
		if (map->i->e)
			mlx_destroy_image(map->mlx, map->i->e);
		if (map->i->win_game)
			mlx_destroy_image(map->mlx, map->i->win_game);
		free(map->i);
	}
	free_array(map);
	free(map);
}

int	close_win(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	ft_free_all(map);
	exit(0);
}
