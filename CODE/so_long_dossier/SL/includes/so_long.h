/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:06 by moni              #+#    #+#             */
/*   Updated: 2024/05/13 15:08:49 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx_LINUX/mlx_int.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "../../includes/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		hauteur;
	int		largeur;
	char	*line;
	char	**map;
}			t_game;

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

void	get_map(char **argv, t_game *lst);
int		borders_are_walls(char **map);
int		check_char(char **map);
int		count_char(char **map);
int		main();

#endif