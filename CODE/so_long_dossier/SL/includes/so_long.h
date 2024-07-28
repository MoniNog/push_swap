/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:06 by moni              #+#    #+#             */
/*   Updated: 2024/07/28 20:29:28 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define AA m->mlx, m->win, m->i->t, x * w, y * h

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

typedef struct s_i
{
	void		*g;
	void		*p;
	void		*t;
	void		*c;
	void		*e;
	void		*win_game;
	int			img_height;
	int			img_width;
	int			img_heightwin;
	int			img_widthwin;
}				t_i;

typedef struct s_map
{
	t_list		*lines;
	int			width;
	int			height;
	int			x;
	int			y;
	char		**array;
	char		**map_copy;
	int			max_coin;
	int			coin;
	t_coor		player;
	t_coor		exit;
	void		*mlx;
	void		*win;
	t_i			*i;
	t_coor		coor;
	int			mouvement;
	int			win_width;
	int			win_height;
	int			game_over;
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
int		get_map(t_map *map, char *mapname);
int		count_height_map(t_map *map);
int		count_char(t_map *map);
int		ft_memcmpext(const void *s1, char *extension);
int		check_char(t_list *map);
int		borders_are_walls(t_map *map);
void	get_array(t_map *map, int l, int h, t_list *lst);
void	start_and_exit_pos(t_map *map);
void	game_init(char *mapname, t_map *map);
int		parse_map(t_map *info);
int		handle_keypress(int keycode, void *param);
void	move_player(t_map *map, int keypress);
void	draw_map(t_map *map, int y);
int		checkers(t_map *map, char *mapname);
int		close_win(t_map *map);
void	ft_free_all(t_map *map);
void	ft_step(t_map *map);
void	victory(t_map *map);
void	free_array(t_map *map);
int		parse_map(t_map *m);
int		path_ok(int x, int y, t_map *m);
void	draw_map2(t_map *m);
void	draw_map1(t_map *m);
int		check_coin(t_map *map);

#endif
