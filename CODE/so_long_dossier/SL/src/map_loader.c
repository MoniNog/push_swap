/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:27 by moni              #+#    #+#             */
/*   Updated: 2024/05/29 12:13:53 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Chargement et manipulation des cartes du jeu. */
#include "../includes/so_long.h"

void	get_map(t_map *map, char *mapname)
{
	int		fd;
	t_list	*ligne;
	int		line_length;

	fd = open(mapname, O_RDONLY);
	
	if (fd == -1)
	{
		ft_printf("error, file can't be opened.\n");
		return;
	}
	ligne = ft_lstnew(get_next_line(fd)); // initialisation 1ere ligne
	
	while (ligne && ligne->content != NULL)
	{
		line_length = ft_strlen((char *)ligne->content);
		if (map->width < line_length)
			map->width = line_length;
		ft_lstadd_back(&(map->lines), ligne); // ajoute ligne a la suite de la carte
		ligne = ft_lstnew(get_next_line(fd)); // lis ligne suivante et je la stocke dans la nouvelle liste (collection de listes)
	}
	
	map->height = count_height_map(map);

	ft_lstiter(map->lines, print_content);

	if (count_char(map->lines) == 1 && check_char(map->lines) == 1)
		printf("SUCCES !");
	else
	ft_printf("\nError map\n");

	ft_printf("\nlargeur : %d\n", map->width);
	ft_printf("hauteur : %d\n", map->height);

	close(fd);

	return ;

}