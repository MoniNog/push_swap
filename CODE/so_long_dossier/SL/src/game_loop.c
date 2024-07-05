/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:09 by moni              #+#    #+#             */
/*   Updated: 2024/07/05 18:36:27 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Contient la boucle principale du jeu et la gestion du temps. */
#include "../includes/so_long.h"

void	move_player(t_map *map, int keypress)
{
	if(keypress == KEY_UP && map->array[map->player.x][map->player.y - 1] != '1')
	{
		map->array[map->player.x][map->player.y] = '0'; // dans ma carte, a la pos du joueur, je mets un char sol 0
		map->player.y = map->player.y - 1;
		map->array[map->player.x][map->player.y] = 'P';
	}
	else if(keypress == KEY_DOWN && map->array[map->player.x][map->player.y - 1] != '1')
	{
		map->array[map->player.x][map->player.y] = '0'; // dans ma carte, a la pos du joueur, je mets un char sol 0
		map->player.y = map->player.y + 1;
		map->array[map->player.x][map->player.y] = 'P';
	}
	else if(keypress == KEY_RIGHT && map->array[map->player.x][map->player.y - 1] != '1')
	{
		map->array[map->player.x][map->player.y] = '0'; // dans ma carte, a la pos du joueur, je mets un char sol 0
		map->player.y = map->player.x + 1;
		map->array[map->player.x][map->player.y] = 'P';
	}
	else if(keypress == KEY_LEFT && map->array[map->player.x][map->player.y - 1] != '1')
	{
		map->array[map->player.x][map->player.y] = '0'; // dans ma carte, a la pos du joueur, je mets un char sol 0
		map->player.y = map->player.x - 1;
		map->array[map->player.x][map->player.y] = 'P';
	}
	else




	// map se modifie pour que position initiale devient sol
	// map se mod pour que la direction designe devienne la pos du player

	// if(je presse key de deplacemnt)
	// 	P se deplace up
	// if la case ou je veux aller est 0
	// 	deplacement
	// if 1
	// 	not possile
	// if c
	// 	c++ dans le compteur et deplacement, la case devient 0
	// if e
	// 	si jai tout les c, end of game.
	// 	si jai pas tout les c, le jeu continue
	
	// refresh map
	return ;
}
// ft_core: Boucle principale du jeu où la logique principale est exécutée.
// event: Gestion des événements d'entrée utilisateur.
// tick: Met à jour le jeu à chaque tick (pour la gestion du temps ou des animations).

// {
// 	map se modifie pour que position initiale devient sol
// 	map se mod pour que la direction designe devienne la pos du player

// 	if(je presse key de deplacemnt)
// 		P se deplace up
// 	if la case ou je veux aller est 0
// 		deplacement
// 	if 1
// 		not possile
// 	if c
// 		c++ dans le compteur et deplacement, la case devient 0
// 	if e
// 		si jai tout les c, end of game.
// 		si jai pas tout les c, le jeu continue
	
// 	refresh map
// 	return ;
// }