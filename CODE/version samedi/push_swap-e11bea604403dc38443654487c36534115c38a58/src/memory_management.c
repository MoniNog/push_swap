/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:48:35 by moni              #+#    #+#             */
/*   Updated: 2024/09/22 18:38:18 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = NULL;
	while (stack)
	{
		temp = stack->next;
		if (stack->struct_price) // Vérifiez si struct_price est alloué
		{
			free(stack->struct_price); // Libérez struct_price
			stack->struct_price = NULL; // Évitez les doubles libérations
		}
		free(stack); // Libérez l'élément de la pile
		stack = temp;
	}
}