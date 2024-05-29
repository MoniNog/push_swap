/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:12:43 by moni              #+#    #+#             */
/*   Updated: 2024/05/29 12:10:08 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int	ft_ismaprectangular(t_list *map)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = 	ft_strlen(map[1]);
// 	while (map[1][i])
// 	{
// 		if (map[1][i] != len)
// 			ft_printf("Error\nMap is not rectangular\n");
// 		i++;
// 	}
// 	return (1);
// }

// int	borders_are_walls(t_list *map)
// {
// 	int i;

// 	i = 0;
// 	ft_printf("1B");
// 	while (map[0][i] != '\n')
// 	{
// 		ft_printf("%c", map[1][i]);
// 		if (map[0][i] == 1)
// 			i++;
// 		else
// 			return (0);
// 		ft_printf("2");
// 	}
// 	while (map[1][i])
// 	{
// 		if (map[1][i] == '\n')
// 		{
// 			if (i + 1 == 1 && i - 1 == 1)
// 				i++;
// 			else
// 				return (0);
// 			ft_printf("3");
// 		}
// 		ft_printf("4");
// 		i++;
// 	}
// 	while (map[1][i] != '\n')
// 	{
// 		if (map[1][i] == 1)
// 			i--;
// 		else
// 			return (0);
// 		ft_printf("5");
// 	}
// 	ft_printf("6");
// 	return (1);
// }

int	check_char(t_list *map)
{
	int		i;
	char	*content;

	while (map != NULL)
	{
		content = (char *)map->content;
		i = 0;
		while(content[i] != '\0')
		{
			if(content[i] == 'P' || content[i] == 'E' || content[i] == 'C'
					|| content[i] == '1' || content[i] == '0'
					|| content[i] == '\n' || content[i] == '\0')
				i++;
			else
				return (0);
		}
		map = map->next;
	}
	if (map == NULL)
		return (1);
	return (0);
}

int	count_char(t_list *map)
{
	int		p;
	int		e;
	int		c;
	int		i;
	char	*content;

	p = 0;
	e = 0;
	c = 0;
	while (map != NULL)
	{
		content = (char *)map->content;
		i = 0;
		while (content[i])
		{
			if (content[i] == 'P')
				p++;
			if (content[i] == 'E')
				e++;
			if (content[i] == 'C')
				c++;
			i++;
		}
		map = map->next;
	}
	if (p == 1 && e == 1 && c > 0)
	{
		return (1);
	}
	else
		return (0);
}
