/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:04 by moni              #+#    #+#             */
/*   Updated: 2024/07/28 20:37:43 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Gestion des entrées utilisateur et des événements système. */
#include "../includes/so_long.h"

int	handle_keypress(int keycode, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keycode == KEY_UP || keycode == KEY_UPP)
		move_player(map, KEY_UP);
	else if (keycode == KEY_DOWN || keycode == KEY_DOWNN)
		move_player(map, KEY_DOWN);
	else if (keycode == KEY_LEFT || keycode == KEY_LEFTT)
		move_player(map, KEY_LEFT);
	else if (keycode == KEY_RIGHT || keycode == KEY_RIGHTT)
		move_player(map, KEY_RIGHT);
	if (keycode == KEY_ESC)
		close_win(map);
	ft_printf("-----------------------------------");
	ft_printf("------------------------------------\n");
	ft_printf("\tNombre de deplacement : %i\t", map->mouvement);
	ft_printf("Fraises restantes : %i\n", map->coin);
	ft_printf("-----------------------------------");
	ft_printf("------------------------------------\n");
	return (0);
}
