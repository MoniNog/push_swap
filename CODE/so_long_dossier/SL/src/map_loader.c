/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:27 by moni              #+#    #+#             */
/*   Updated: 2024/05/13 16:02:33 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Chargement et manipulation des cartes du jeu. */
#include "../includes/so_long.h"

void	get_map(char **argv, t_game *lst)
{
	char	*s1 = NULL;
	char	*s2 = NULL;
	char	*tmp = NULL;
	char	**map = NULL;
	int		fd = 0;
	int		i = 0;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
	{
		ft_printf("Error, file can't be open.\n");
		return;
	}
		ft_printf("1\n");
	s1 = get_next_line(fd); // pourquoi ca marche pas ?
	// ft_printf("%s", s1);
	// ft_printf("%c", s1[0]);
	if (!s1)
		ft_printf("vroum");
	while (s1)
	{
		tmp = ft_strjoin(s2, s1);
		free(s1);
		free(s2);
		s2 = get_next_line(fd);
		ft_printf("lalala");
	}
	ft_printf("2\n");
	ft_printf("%s", s1);
	ft_printf("%s", tmp);
	lst->map = ft_split(s2, '\n');
	ft_printf("3");
	if (map == NULL)
	{
		ft_printf("4");
		return ;
	}
	ft_printf("5");
	while (map && map[i])
	{
		if (map[i] != NULL)
			ft_printf("%s\n", map[i]);
		i++;
	}
	ft_printf("6\n");
	lst->map = map;
	free(s2);
	while (i--)
		free(map[i]);
	free(map);
	close(fd);
}
// get_map, map_core, get_height, fill_map, change_map_borders, change_wall_in_map,
// add_randomness: Charge et manipule la carte du jeu.

int	main(int argc, char **argv)
{
	t_game	lst;
	
	if (argc == 2)
	{
		get_map(argv, &lst);
		ft_printf("%s", lst.map[0]);
		if (borders_are_walls(lst.map) == 1)
		{
			ft_printf("ERROR");
			return 0;
		}
		ft_printf("SUCCES");
	}
	return(0);
}