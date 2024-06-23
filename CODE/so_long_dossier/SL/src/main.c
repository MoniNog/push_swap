/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:19 by moni              #+#    #+#             */
/*   Updated: 2024/06/23 19:04:19 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Point d'entrée du programme. Gestion des arguments et démarrage du jeu. */
#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	carte;

	carte.lines = NULL;
	carte.width = 0;
	carte.height = 0;
	if (argc == 2 && ft_memcmpext(argv[1], ".ber") == 1)
	{
		get_map(&carte, argv[1]);
		get_array(&carte);
		//CHECKERS
		if (count_char(&carte) == 1)
			ft_printf("\n Count char ok :)\n");
		if (check_char(carte.lines) == 1)
			ft_printf("\n Check char ok :)\n");
		if (borders_are_walls(&carte) == 1)
			ft_printf("\n Borders ok :)\n");
		// if (count_char(&carte) == 1 && check_char(carte.lines) == 1 && borders_are_walls(&carte) == 1)
		ft_printf("\ncoinmax : %d\n", carte.coinmax);
		// ft_printf("\nlargeur : %d\n", carte->width);
		// ft_printf("hauteur : %d\n", carte->height);

		game_init("salut", &carte);
	}
	return (0);
}