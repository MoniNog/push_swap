/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:31 by moni              #+#    #+#             */
/*   Updated: 2024/07/26 12:13:52 by moni             ###   ########.fr       */
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
	if (map->img)
	{
		if (map->img->tree)
			mlx_destroy_image(map->mlx, map->img->tree);
		if (map->img->grass)
			mlx_destroy_image(map->mlx, map->img->grass);
		if (map->img->girl)
			mlx_destroy_image(map->mlx, map->img->girl);
		if (map->img->flower)
			mlx_destroy_image(map->mlx, map->img->flower);
		if (map->img->basket)
			mlx_destroy_image(map->mlx, map->img->basket);
		if (map->img->win_game)
			mlx_destroy_image(map->mlx, map->img->win_game);
		free(map->img);
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
