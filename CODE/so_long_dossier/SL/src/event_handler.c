/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:04 by moni              #+#    #+#             */
/*   Updated: 2024/05/29 12:12:48 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Gestion des entrées utilisateur et des événements système. */
#include "../includes/so_long.h"

// int handle_keypress(int keycode, void *param)
// {
// 	t_game *game;
// 	game = (t_game *)param;

// 	if (keycode == KEY_UP)
// 		move_player(game, UP);
// 	else if (keycode == KEY_DOWN)
// 		move_player(game, DOWN);
// 	else if (keycode == KEY_LEFT)
// 		move_player(game, LEFT);
// 	else if (keycode == KEY_RIGHT)
// 		move_player(game, RIGHT);
// 	else if (keycode == KEY_ESC)
// 		exit(0);
// 	return (0);
// }
// int key_hook(int keycode, t_game *game)
// {
// 	printf("Keycode: %d\n", keycode);
// 	if (keycode == 65307)
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		exit(0);
// 	}
// 	return (0);
// }

// key_hook, key_press, key_pressed, key_released: Gestion des entrées clavier.
// close_win, close_game: Gère la fermeture de la fenêtre et la sortie du jeu.