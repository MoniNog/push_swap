/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:09 by moni              #+#    #+#             */
/*   Updated: 2024/07/22 14:42:56 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Contient la boucle principale du jeu et la gestion du temps. */
#include "../includes/so_long.h"

void	key_press_up(t_map *map)
{
	if(map->coin == 0 && (map->player.x == map->exit.x && map->player.y - 1 == map->exit.y))
		{
			victory(map);
			return ;
		}
	else
	{
	if (map->player.x == map->exit.x && map->player.y == map->exit.y)
		map->array[map->player.y][map->player.x] = 'E';
	else
		map->array[map->player.y][map->player.x] = '0';
	map->player.y = map->player.y - 1;

	if(map->array[map->player.y][map->player.x] == 'C')
		map->coin--;
	map->array[map->player.y][map->player.x] = 'P';
	map->mouvement++;
	}
	draw_map(map);
	return ;
}

void	key_press_down(t_map *map)
{
	if(map->coin == 0 && (map->player.x == map->exit.x && map->player.y + 1 == map->exit.y))
		{
			victory(map);
			return ;
		}
	else
	{
		if (map->player.x == map->exit.x && map->player.y == map->exit.y)
			map->array[map->player.y][map->player.x] = 'E';
		else
			map->array[map->player.y][map->player.x] = '0';
		map->player.y = map->player.y + 1;
		if(map->array[map->player.y][map->player.x] == 'C')
			map->coin--;
		map->array[map->player.y][map->player.x] = 'P';
		map->mouvement++;
	}
	draw_map(map);
	return ;
}

void	key_press_right(t_map *map)
{
	if(map->coin == 0 && (map->player.x == map->exit.x + 1 && map->player.y == map->exit.y))
	{
		victory(map);
		return ;
	}
	if (map->player.x == map->exit.x && map->player.y == map->exit.y)
		map->array[map->player.y][map->player.x] = 'E';
	else
		map->array[map->player.y][map->player.x] = '0';
	map->player.x = map->player.x + 1;
	if(map->array[map->player.y][map->player.x] == 'C')
		map->coin--;
	map->array[map->player.y][map->player.x] = 'P';
		map->mouvement++;
	draw_map(map);
	return ;
}

void	key_press_left(t_map *map)
{
	if(map->coin == 0 && (map->player.x == map->exit.x - 1 && map->player.y == map->exit.y))
	{
		victory(map);
		return ;
	}
	if (map->player.x == map->exit.x && map->player.y == map->exit.y)
		map->array[map->player.y][map->player.x] = 'E';
	else
		map->array[map->player.y][map->player.x] = '0';
	map->player.x = map->player.x - 1;
	if(map->array[map->player.y][map->player.x] == 'C')
		map->coin--;
	map->array[map->player.y][map->player.x] = 'P';
		map->mouvement++;
	draw_map(map);
	return ;
}

void	move_player(t_map *map, int keypress)
{
	if(keypress == KEY_UP && map->array[map->player.y - 1][map->player.x] != '1')
		key_press_up(map);
	else if(keypress == KEY_DOWN && map->array[map->player.y + 1][map->player.x] != '1')
		key_press_down(map);
	else if(keypress == KEY_RIGHT && map->array[map->player.y][map->player.x + 1] != '1')
		key_press_right(map);
	else if(keypress == KEY_LEFT && map->array[map->player.y][map->player.x - 1] != '1')
		key_press_left(map);
}