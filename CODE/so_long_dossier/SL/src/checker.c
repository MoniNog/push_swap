/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:12:43 by moni              #+#    #+#             */
/*   Updated: 2024/07/26 11:11:26 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fonctions permettant de verifier si la carte est valide avant de lancerlejeu
#include "../includes/so_long.h"

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
	int		c;
	int		i;
	t_list	*current;

	p = 0;
	e = 0;
	c = 0;
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
			if (((char *)current->content)[i] == 'C')
				c++;
			i++;
		}
		current = current->next;
	}
	if (p == 1 && e == 1 && c > 0)
	{
		map->max_coin = c;
		return (1);
	}
	else
		return (0);
}

static int	path_ok(int x, int y, t_map *m)
{
	int	res;

	res = 0;
	if (y >= m->height || x >= m->width || y < 0 || x < 0
		|| m->map_copy[y][x] == '1' || m->map_copy[y][x] == '2')
		return (0);
	else if (m->map_copy[y][x] == 'E')
		return (1);
	else if (m->map_copy[y][x] == 'C')
		m->coin++;
	m->map_copy[y][x] = '2';
	res += path_ok(x, y - 1, m);
	res += path_ok(x, y + 1, m);
	res += path_ok(x + 1, y, m);
	res += path_ok(x - 1, y, m);
	return (res);
}

int	parse_map(t_map *m)
{
	m->coin = 0;
	if (path_ok(m->player.x, m->player.y, m) && m->coin == m->max_coin)
		return (1);
	return (0);
}
