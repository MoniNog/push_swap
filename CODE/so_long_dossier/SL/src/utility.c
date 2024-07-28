/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:42 by moni              #+#    #+#             */
/*   Updated: 2024/07/28 14:25:41 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_height_map(t_map *map)
{
	int		i;
	t_list	*current;

	i = 0;
	current = map->lines;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	start_and_exit_pos(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (map->array[row][col] == 'P')
			{
				map->player.x = col;
				map->player.y = row;
			}
			if (map->array[row][col] == 'E')
			{
				map->exit.x = col;
				map->exit.y = row;
			}
			col++;
		}
		row++;
	}
	return ;
}

int	path_ok(int x, int y, t_map *map)
{
	int	res;

	res = 0;
	if (y >= map->height || x >= map->width || y < 0 || x < 0
		|| map->map_copy[y][x] == '1' || map->map_copy[y][x] == '2')
		return (0);
	else if (map->map_copy[y][x] == 'E')
		return (1);
	else if (map->map_copy[y][x] == 'C')
		map->coin++;
	map->map_copy[y][x] = '2';
	res += path_ok(x, y - 1, map);
	res += path_ok(x, y + 1, map);
	res += path_ok(x + 1, y, map);
	res += path_ok(x - 1, y, map);
	return (res);
}

int	parse_map(t_map *map)
{
	map->coin = 0;
	if (path_ok(map->player.x, map->player.y, map)
		&& map->coin == map->max_coin)
		return (1);
	return (0);
}
