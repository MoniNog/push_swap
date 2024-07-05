/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:04 by moni              #+#    #+#             */
/*   Updated: 2024/07/05 18:46:55 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Gestion des entrées utilisateur et des événements système. */
#include "../includes/so_long.h"

// int	close_win(int keycode, t_map *map)
// {
// 	}
// 	return (0);
// }

int handle_keypress(int keycode, void *param)
{
	t_map *map;
	map = (t_map *)param;

	printf("Keycode: %d\n", keycode);
	if (keycode == KEY_UP)
		move_player(map, KEY_UP);
	else if (keycode == KEY_DOWN)
		move_player(map, KEY_DOWN);
	else if (keycode == KEY_LEFT)
		move_player(map, KEY_LEFT);
	else if (keycode == 65363)
		move_player(map, KEY_RIGHT);
	if (keycode == 65307)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	draw_map(map->array);
	return (0);
}


// // key_hook, key_press, key_pressed, key_released: Gestion des entrées clavier.
// // close_win, close_map: Gère la fermeture de la fenêtre et la sortie du jeu.