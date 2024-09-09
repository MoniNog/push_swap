// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   int*c.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/08/29 13:18:48 by moni              #+#    #+#             */
// /*   Updated: 2024/08/31 19:04:54 by moni             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../../includes/pushswap.h"

// void	ft_swap(int *a, int *b)
// {
// 	int		temp;

// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// int	*dup_a_to_c(t_stack **stack, t_info *info)
// {
// 	int			i;
// 	int			*c;

// 	i = 0;
// 	c = malloc(sizeof(int));
// 	if (!c)
// 		return (NULL);
// 	while (*stack)
// 	{
// 		c[i]= (*stack)->content;
// 		i++;
// 		*stack = (*stack)->next;
// 	}
	
	
// 	int		*j;

// 	j = 0;
// 	while (j < info->size)
// 	{
// 		printf("index - [ %i ] --- content : [ %i ]\n", j, c[j]);
// 		j++;
// 	}
// }

// 	// int		a;
// 	// int 	*temp;
	
// 	// a = 0;

// 	// while (a != info->size)
// 	// {
// 	// 	if (&c[a + 1] == NULL)
// 	// 		break ;
		
// 	// 	if (&c[a] > &c[a + 1])
// 	// 	{
// 	// 		temp = c[a];
// 	// 		*c[a] = *c[a + 1];
// 	// 		*c[a + 1] = temp;
// 	// 	}
// 	// 	a++;
// 	// }
// 	return (c);
// }