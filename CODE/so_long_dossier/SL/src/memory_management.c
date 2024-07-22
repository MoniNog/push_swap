/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:31 by moni              #+#    #+#             */
/*   Updated: 2024/07/22 14:32:36 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Gestion de la libération de la mémoire pour différentes structures. */
#include "../includes/so_long.h"


void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_all(t_map *map)
{
	ft_lstclear(&(map->lines), free);
	free_map(map->array);
	if (map->img)
		{
			// Libère chaque image si elles sont allouées dynamiquement
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
}

int	close_win(t_map *map)
{
		mlx_destroy_window(map->mlx, map->win);
		ft_free_all(map);
		exit(0);
}

// ft_free_map, ft_free_all, free_map, free_stash, free_player, free_foe, free_trap,
// free_staff, free_scroll, free_collect, free_exit, free_collision: Gère la 
// libération de la mémoire pour différentes structures.