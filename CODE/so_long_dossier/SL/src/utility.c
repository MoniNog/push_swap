/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:42 by moni              #+#    #+#             */
/*   Updated: 2024/07/26 12:01:01 by moni             ###   ########.fr       */
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

void	print_content(void *content)
{
	ft_printf("%s", (char *)content);
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

