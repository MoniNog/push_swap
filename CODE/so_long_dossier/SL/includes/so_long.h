/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:38:06 by moni              #+#    #+#             */
/*   Updated: 2024/05/29 11:42:15 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx_LINUX/mlx_int.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct s_map
{
	t_list	*lines;
	int		width;
	int		height;
}			t_map;

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363;

// t_list	*ft_lstnew(void *content);
// void	ft_lstadd_back(t_list **lst, t_list *new);
// void	ft_lstiter(t_list *lst, void (*f)(void *));
void	print_content(void *content);
void	get_map(t_map *map, char *mapname);
int		count_height_map(t_map *map);
int		count_char(t_list *map);
int		ft_memcmpext(const void *s1, char *extension);
int		check_char(t_list *map);

#endif