/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:06 by moni              #+#    #+#             */
/*   Updated: 2024/06/23 18:59:07 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx_LINUX/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct s_coor
{
	int		x;
	int		y;
}			t_coor;

typedef struct	s_map
{
	t_list		*lines;
	int			width;
	int			height;
	char		**array;
	char		**testissue;// for check if win possible
	int			coinmax;// number of coins in the map for compare with win possible
	t_coor		start;// pos of P
	t_coor		exit;// pos of E
	void		*mlx;
	void		*win;
	void		*img;
}				t_map;

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363;

void	print_content(void *content);
void	get_map(t_map *map, char *mapname);
int		count_height_map(t_map *map);
int		count_char(t_map *map);
int		ft_memcmpext(const void *s1, char *extension);
int		check_char(t_list *map);
int		borders_are_walls(t_map *map);
void	get_array(t_map *map);
void	start_and_exit_pos(t_map *map);
int		close_win(int keycode, t_map *map);
t_map	*game_init(char *mapname, t_map * map);


#endif