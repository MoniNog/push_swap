/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:48:35 by moni              #+#    #+#             */
/*   Updated: 2024/09/10 17:59:10 by moni             ###   ########.fr       */
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
		free(stack);
		stack = temp;
	}
}
