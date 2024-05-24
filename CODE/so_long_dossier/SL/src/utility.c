/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:42 by moni              #+#    #+#             */
/*   Updated: 2024/05/16 15:14:20 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Fonctions utilitaires pour le jeu, telles que la gestion des erreurs et la validation. */

#include <stdio.h>
#include "../includes/so_long.h"

int	count_height_map(fd)
{
	int	i;
	int	ligne;
	char	**map;

	i = 0;
	ligne = 0;
	**map = open(fd, O_RDONLY);
	while(map[i])
	{
		if (map[y][x] == '\n')
			ligne++;
		i++;
	}
	return (ligne);
}

char	**open_map(fd)

int	main(int argc, char **argv)
{
	argc(void);
	int a = count_height_map(argv[1]);
	printf("%i", a);
	return (0);
}
// ft_error, ft_check_win, ft_step, check_collide, check_border, check_all_char,
// check_map, check_map_proportions, check_map_mandatory, is_char_valid, find_char_player,
// is_next_char_ok, map_error, mana_management, mana_regen, mana_cost_fly, probability:
// Diverses fonctions utilitaires pour la gestion des erreurs, la validation de 
// la carte, et d'autres opérations d'assistance.
