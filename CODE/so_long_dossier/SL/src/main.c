/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:19 by moni              #+#    #+#             */
/*   Updated: 2024/07/28 20:29:44 by moni             ###   ########.fr       */
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
	map->i = NULL;
	if (get_map(map, argv[1]) == 1)
	{
		free(map);
		return (0);
	}
	get_array(map, map->width, map->height, map->lines);
	start_and_exit_pos(map);
	if (argc == 2 && checkers(map, argv[1]) == 1 && check_coin(map) == 1)
		game_init("So_long by monoguei (ce fut long en effet !)", map);
	else
		ft_free_all(map);
	return (0);
}
