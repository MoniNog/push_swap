/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:19 by moni              #+#    #+#             */
/*   Updated: 2024/05/29 12:19:09 by moni             ###   ########.fr       */
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
	}
	return (0);
}