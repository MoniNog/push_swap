/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:38 by moni              #+#    #+#             */
/*   Updated: 2024/05/10 15:43:05 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Chargement et gestion des textures du jeu. */

void *select_img(int map_value, t_game *game)
{
	if (map_value == 1)
		return game->img_wall;
	else if (map_value == 0)
		return game->img_floor;
	else if (map_value == 'C')
		return game->img_collectible;
	return NULL;
}
// set_img: Charge les textures utilisées dans le jeu.