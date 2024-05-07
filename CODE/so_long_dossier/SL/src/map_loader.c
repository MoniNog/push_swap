/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:27 by moni              #+#    #+#             */
/*   Updated: 2024/05/07 16:48:00 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Chargement et manipulation des cartes du jeu. */
#include "../includes/so_long.h"

void	get_map(char **argv)
{
	char	*s1;
	char	*s2;
	char	*tmp1;
	char	*tmp2;
	char	**map;
	int		fd;
	int		i = 0;

	fd = open(argv[1], O_RDONLY, 0777);
	s1 = get_next_line(fd);
	tmp1 = NULL;
	tmp2 = NULL;
	s2 = tmp1;
	if (!s1)
		ft_printf("Error, file can't be open.\n");
	while (s1 != NULL)
	{
		s2 = ft_strjoin(s2, s1);
		free(s2);
		s2 = tmp2;
		free(s1);
		s1 = get_next_line(fd);
	}
	map = ft_split(s2, '\n');
	while(map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	free(s2);
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