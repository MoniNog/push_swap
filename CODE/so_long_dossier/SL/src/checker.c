/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:12:43 by moni              #+#    #+#             */
/*   Updated: 2024/07/28 20:28:59 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fonctions permettant de verifier si la carte est valide avant de lancerlejeu
#include "../includes/so_long.h"

int	check_coin(t_map *map)
{
	if (map->max_coin < 1)
	{
		ft_printf("\nError : Invalid map -> Any collectible\n");
		return (0);
	}
	else
		return (1);
}

int	checkers(t_map *map, char *mapname)
{
	if (ft_memcmpext(mapname, ".ber") != 1)
	{
		ft_printf("\nError : Invalid map -> Wrong extension\n");
		return (0);
	}
	if (count_char(map) != 1 || check_char(map->lines) != 1)
	{
		ft_printf("\nError : Invalid map -> Error char\n");
		return (0);
	}
	if (borders_are_walls(map) != 1)
	{
		ft_printf("\nError : Invalid map -> Borders aren't all walls\n");
		return (0);
	}
	if (parse_map(map) != 1)
	{
		ft_printf("\nError : Invalid map -> Any issue possible\n");
		return (0);
	}
	return (1);
}


//verifier dans les checkers pouruqoi le 2eme appel ne fonctionne pas.
// modification de la map une fois checke ?

int	borders_are_walls(t_map *map)
{
	int		row;
	int		col;

	map->max_coin = 0;
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (row == 0 || row == (map->height - 1) || col == 0
				|| col == (map->width - 1))
				if (map->array[row][col] != '1')
					return (0);
			if (map->array[row][col] == 'C')
				map->max_coin++;
			col++;
		}
		row++;
	}
	return (1);
}

int	check_char(t_list *ligne)
{
	int		i;
	char	*str;

	if (!ligne)
		return (0);
	while (ligne != NULL)
	{
		str = (char *)ligne->content;
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == 'P' || str[i] == 'E' || str[i] == 'C'
				|| str[i] == '1' || str[i] == '0'
				|| str[i] == '\n' || str[i] == '\0')
				i++;
			else
				return (0);
		}
		ligne = ligne->next;
	}
	return (1);
}

int	count_char(t_map *map)
{
	int		p;
	int		e;
	int		i;
	t_list	*current;

	p = 0;
	e = 0;
	current = map->lines;
	while (current)
	{
		i = 0;
		while (((char *)current->content)[i])
		{
			if (((char *)current->content)[i] == 'P')
				p++;
			if (((char *)current->content)[i] == 'E')
				e++;
			i++;
		}
		current = current->next;
	}
	if (p == 1 && e == 1)
		return (1);
	else
		return (0);
}
