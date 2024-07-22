/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:06 by moni              #+#    #+#             */
/*   Updated: 2024/07/22 13:10:03 by moni             ###   ########.fr       */
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

typedef struct s_img
{
	void		*grass;
	void		*girl;
	void		*tree;
	void		*flower;
	void		*basket;
	void		*win_game;
	int			img_height;
	int			img_width;
	int			img_heightwin;
	int			img_widthwin;
}				t_img;

typedef struct	s_map
{
	t_list		*lines;
	int			width;
	int			height;
	int			x;
	int			y;
	char		**array;
	char		**map_copy;// for check if win possible
	int			max_coin;// number of coins in the map for compare with win possible
	int			coin;
	t_coor		player;// pos of P
	t_coor		exit;// pos of E
	void		*mlx;
	void		*win;
	t_img		*img;
	t_coor		coor;
	int			mouvement;
	int			win_width;
	int			win_height;
}				t_map;


# define KEY_ESC 65307
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_UPP 65362
# define KEY_DOWNN 65364
# define KEY_LEFTT 65361
# define KEY_RIGHTT 65363


void	print_content(void *content);
void	get_map(t_map *map, char *mapname);
int		count_height_map(t_map *map);
int		count_char(t_map *map);
int		ft_memcmpext(const void *s1, char *extension);
int		check_char(t_list *map);
int		borders_are_walls(t_map *map);
void	get_array(t_map *map, int l, int h, t_list *lst);
void	start_and_exit_pos(t_map *map);
// int		close_win(int keycode, t_map *map);
void	game_init(char *mapname, t_map *map);
int		parse_map(t_map *info);
int		handle_keypress(int keycode, void *param);
void	move_player(t_map *map, int keypress);
void	draw_map(t_map *map);
int		checkers(t_map *map, char *mapname);
// int		close(int keycode, t_map *map);
int		close_win(t_map *map);
void	ft_free_all(t_map *map);
void	ft_step(t_map *map);
void	victory(t_map *map);



#endif