/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:27 by moni              #+#    #+#             */
/*   Updated: 2024/07/26 12:28:00 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Chargement et manipulation des cartes du jeu. */
#include "../includes/so_long.h"

int	get_map(t_map *map, char *mapname)
{
	t_list	*line;
	int		fd;

	fd = open(mapname, O_RDONLY);
	if (fd == -1)
	{
		perror("Error, file can't be opened.\n");
		return (1);
	}
	line = ft_lstnew(get_next_line(fd));
	if (!line)
	{
		ft_printf("Error : map empty\n");
		return (1);
	}
	map->width = ft_strlen((char *)line->content) - 1;
	while (line && line->content != NULL)
	{
		ft_lstadd_back(&(map->lines), line);
		line = ft_lstnew(get_next_line(fd));
	}
	map->height = count_height_map(map);
	close(fd);
	free(line);
	return (0);
}

void	get_array(t_map *map, int l, int h, t_list *lst)
{
	int		i;

	i = 0;
	map->array = malloc(h * sizeof(char *));
	map->map_copy = malloc(h * sizeof(char *));
	if (!map->array || !map->map_copy)
		return ;
	while (i < h)
	{
		map->array[i] = (char *)malloc((l));
		map->map_copy[i] = (char *)malloc((l));
		if (!map->array[i] || !map->map_copy[i])
			return ;
		ft_strlcpy(map->array[i], lst->content, l + 1);
		ft_strlcpy(map->map_copy[i], lst->content, l + 1);
		i++;
		lst = lst->next;
	}
	return ;
}
