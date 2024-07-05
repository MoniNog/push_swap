/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:12:43 by moni              #+#    #+#             */
/*   Updated: 2024/07/05 11:49:32 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fonctions permettant de verifier si la carte est valide avant de lancer le jeu
#include "../includes/so_long.h"

int		borders_are_walls(t_map *map)
{
	int		row;
	int		col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (row == 0 || row == (map->height - 1) || col == 0 || col == (map->width - 1)) //check si bord
				if (map->array[row][col] != '1')
					return (0);
			col++;
		}	
		row++;
	}
	return (1);
}

int		check_char(t_list *ligne)
{
	int		i;
	char	*str;
	
	if (!ligne)
		return (0);
	while (ligne != NULL)
	{
		str = (char *)ligne->content;
		i = 0;
		while(str[i] != '\0')
		{
			if(str[i] == 'P' || str[i] == 'E' || str[i] == 'C'
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

int		count_char(t_map *map)
{
	int		p;
	int		e;
	int		c;
	int		i;
	t_list*	current;
	char	*content;

	p = 0;
	e = 0;
	c = 0;
	current = map->lines;// initialiser le curseur et on lui dit ou il commence a lire
	
	while (current)// tant que le curseur pointe sur qqch
	{
		content = current->content;// current == curseur, represente la ou je me trouve
		i = 0;
		while (content[i])
		{
			if (content[i] == 'P')
				p++;
			if (content[i] == 'E')
				e++;
			if (content[i] == 'C')
				c++;
			i++;
		}
		current = current->next;// on fait avancer le curseur
	}
	if (p == 1 && e == 1 && c > 0)
	{
		map->max_coin = c;
		return (1);
	}
	else
		return (0);
}

static int	path_ok(int x, int y, t_map *info)
{
	int	res;

	res = 0;
	if (y >= info->height || x >= info->width || y < 0 || x < 0
		|| info->map_copy[y][x] == '1' || info->map_copy[y][x] == '2')
		return (0);
	else if (info->map_copy[y][x] == 'E')
		return (1);
	else if (info->map_copy[y][x] == 'C')
		info->coin++;
	info->map_copy[y][x] = '2';
	res += path_ok(x, y - 1, info);
	res += path_ok(x, y + 1, info);
	res += path_ok(x + 1, y, info);
	res += path_ok(x - 1, y, info);
	return (res);
}

int	parse_map(t_map *info)
{
	info->coin = 0;
	if (path_ok(info->player.x, info->player.y, info) && info->coin == info->max_coin)
		return (1);
	return (0);
}


// int	ft_error(int error)
// {
// 	if (error == 1)
// 		ft_printf("File error: ouverture impossible de fichier\n");
// 	else if (error == 2)
// 		ft_printf("Map error.\n");
// 	else if (error == 3)
// 		ft_printf("Map error: aucun chemin possible.\n");
// 	else if (error == 4)
// 		ft_printf("Map error: forme non conforme.\n");
// 	else if (error == 5)
// 		ft_printf("Map error: taille non conforme.\n");
// 	else if (error == 6)
// 		ft_printf("Map error: les murs doivent être seulement des '1'.\n");
// 	else if (error == 7)
// 		ft_printf("Map error: syntaxe ('1', '0', 'E', 'F', 'P' ou 'x').\n");
// 	else if (error == 8)
// 		ft_printf("Map error: 1 player, 1 exit, min. 1 item.\n");
// 	else if (error == 9)
// 		ft_printf("Malloc error.\n");
// 	else if (error == 10)
// 		ft_printf("Map error: item inatteignable.\n");
// 	else if (error == 11)
// 		ft_printf("File error: extension non reconnue.\n");
// 	return (0);
// }

// 		return (ft_error(8));
