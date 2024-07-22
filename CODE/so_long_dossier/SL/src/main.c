/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:19 by moni              #+#    #+#             */
/*   Updated: 2024/07/22 14:27:30 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Point d'entrée du programme. Gestion des arguments et démarrage du jeu. */
#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->lines = NULL;
	map->width = 0;
	map->height = 0;
	get_map(map, argv[1]);
	get_array(map, map->width, map->height, map->lines);
	start_and_exit_pos(map);
	if (argc == 2 && checkers(map, argv[1]) == 1)
		game_init("So_long by monoguei (ce fut long en effet !)", map);
	return (0);
}