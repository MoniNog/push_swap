/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:31 by moni              #+#    #+#             */
/*   Updated: 2024/05/29 12:16:56 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Gestion de la libération de la mémoire pour différentes structures. */
#include "../includes/so_long.h"
// void	free_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
// }

// ft_free_map, ft_free_all, free_map, free_stash, free_player, free_foe, free_trap,
// free_staff, free_scroll, free_collect, free_exit, free_collision: Gère la 
// libération de la mémoire pour différentes structures.