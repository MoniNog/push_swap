/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:27 by moni              #+#    #+#             */
/*   Updated: 2024/06/14 12:27:34 by moni             ###   ########.fr       */
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
	map->width = ft_strlen((char *)ligne->content) -1; // initialisation width (-1 pour enlever le \n
//BOUCLE
	while (ligne && ligne->content != NULL)
	{
		line_length = ft_strlen((char *)ligne->content);
		if (map->width < line_length -1) // -1 pour ajuster valeur largeur, supp \n
		{
			ft_printf("Error\nMap is not rectangular :(");
			return ;
		}
		ft_lstadd_back(&(map->lines), ligne); // ajoute ligne a la suite de la carte
		ligne = ft_lstnew(get_next_line(fd)); // lis ligne suivante et je la stocke dans la nouvelle liste (collection de listes)
	}

//STOCK HAUTEUR
	map->height = count_height_map(map);

//PRINT MAP
	ft_printf("liste chainee : \n"); 
	ft_lstiter(map->lines, print_content);

	ft_printf("\n\nHauteur : %i", map->height);
	ft_printf("\nLargeur : %i\n", map->width);
	
	close(fd);
	return ;
}

void	get_array(t_map *map)
{
	int		l;
	int		h;
	int		i;
	t_list	*lst;

	l = map->width;
	h = map->height;
	i = 0;
	lst = map->lines;

	map->array = malloc(h * sizeof(char *));
	map->testissue = malloc(h * sizeof(char *));
	if (!map->array)
		return ;

	while (i < h)
	{
		map->array[i] = (char *)malloc((l));
		map->testissue[i] = (char *)malloc((l));
		if (!map->array[i] || !map->testissue[i])
		// if (!map->array[i] )
			return ;
		i++;
	}

	i = 0;
	while (i < h)
	{
		ft_strlcpy(map->array[i], lst->content, l + 1);
		ft_strlcpy(map->testissue[i], lst->content, l + 1);
		i++;
		lst = lst->next; // equivalent de i++ pour liste chainee
	}
// PRINT ARRAY FOR CHECKING
	i = 0;
	while (i < h)
	{
		ft_printf("\narray : %s", map->array[i]);
		i++;
	}

	ft_printf("\n\n");

	i = 0;
	while (i < h)
	{
		ft_printf("\narray : %s", map->testissue[i]);
		i++;
	}
	return ;
}
