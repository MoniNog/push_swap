/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:19 by moni              #+#    #+#             */
/*   Updated: 2024/07/05 18:18:14 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Point d'entrée du programme. Gestion des arguments et démarrage du jeu. */
#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*carte;

	carte = malloc(sizeof(t_map));
	carte->lines = NULL;
	carte->width = 0;
	carte->height = 0;
	if (argc == 2 && ft_memcmpext(argv[1], ".ber") == 1)
	{
		get_map(carte, argv[1]);
		get_array(carte);
// [_] condition checkers are ok permet de poursuivre
	//CHECKERS
		// if (count_char(&carte) == 1)
		// 	ft_printf("\n Count char ok :)\n");
		// if (check_char(carte.lines) == 1)
		// 	ft_printf("\n Check char ok :)\n");
		// if (borders_are_walls(&carte) == 1)
		// 	ft_printf("\n Borders ok :)\n");
		// ft_printf("\ncoinmax : %d\n", carte.max_coin);
		start_and_exit_pos(carte);
		ft_printf("\nposition player x : %i\n", carte->player.x);
		ft_printf("\nposition player y : %i\n\n\n", carte->player.y);
		// ft_printf("issue impossible = 0 \nissue possible = 1\n resultat : %i\n", parse_map(&carte));
		// ft_printf("\ncoin : %d\n", carte.coin);
		game_init("42", carte);
	}
	return (0);
}