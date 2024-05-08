/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:27 by moni              #+#    #+#             */
/*   Updated: 2024/05/08 19:44:27 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Chargement et manipulation des cartes du jeu. */
#include "../includes/so_long.h"

void	get_map(char **argv)
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
	s1 = get_next_line(fd);
	while (s1 != NULL)
	{
		tmp = ft_strjoin(s2, s1);
		free(s1);
		free(s2);
		s2 = tmp;
	}
	if (s2 == NULL)
		return;
	map = ft_split(s2, '\n');
	while(map && map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
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
	if (argc != 2)
		return(0);
	get_map(argv);
	return(0);
}