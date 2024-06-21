/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:12:43 by moni              #+#    #+#             */
/*   Updated: 2024/06/14 18:27:23 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		map->coinmax = c;
		return (1);
	}
	else
		return (0);
}

// int		recursive(t_map *map, char **flag(tableau 2d), int x, int y)
// si xy n-est pas encore check (flag)
// 	flag xy afin de ne par refaire la meme coordonnee
// 	si autour de ce point les sols ou collectibles
// 		recursive(x,y)
// 	si E stop - return ok
	

// cherche P
// identifier les 0/C autour de telle position -> fill
// pour chaque coor valide, refill (recursif) refaire ca...
// jusqua trouver E
// !! appels infinis ne pas recheck les cases deja checke, comment marquer les cases ? flag ?
// transformer en mur quand cest check !! faire une copie
// faire un deuxieme tableau servant de condition pour tester si deja check ou pas avant de relancer la recursive



// static int	path_ok(int y, int x, int *coin, t_game *info)
// {
// 	int	res;

// 	res = 0;
// 	if (y >= info->y || x >= info->x || y < 0 || x < 0
// 		|| info->map_copy[y][x] == '1' || info->map_copy[y][x] == '2')
// 		return (0);
// 	else if (info->map_copy[y][x] == 'E')
// 		return (1);
// 	else if (info->map_copy[y][x] == 'C')
// 		(*coin)++;
// 	info->map_copy[y][x] = '2';
// 	res += path_ok(y + 1, x, coin, info);
// 	res += path_ok(y - 1, x, coin, info);
// 	res += path_ok(y, x + 1, coin, info);
// 	res += path_ok(y, x - 1, coin, info);

// // 	return (res);
// // }

// int	check_path : // if (c == map.coinmax)
// 		return (1);

// void	fill(int x, int y, int c, t_map **start, t_map *mapcopy)
// //							 ??
// {
// 	mapcopy = map->testissue;

// 	map.start == '2';
// 	// dans mapcopy je pars depuis la pos start

// depuis map.start
// si x±1 ou y±1 == 0		devient 2					FILL
// si x±1 ou y±1 == 1		STOP
// si x±1 ou y±1 == C		c++		compter pour comparer ensuite avec coinmax. 
// 								puis devient 2		FILL (c+1)
// si x±1 ou y±1 == E		sortie possible		
// 										c collecter =?= coinmax -> a mettre dans la fonction path_ok
// 												RETURN 1	SUCCESS POSSIBLE
// 						mais comment continuer a checker sans ommettre de C ?
// 						check si jai recup tous les C si oui return 1
	
// 	return (0);
// }
