/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:52:37 by moni              #+#    #+#             */
/*   Updated: 2024/09/08 10:13:37 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int			index;

	index = 0;
	// if (!stack_a)
	// {
	// 	printf("\033[1;34m\n┌───────────────┐\n");
	// 	printf("│ Empty stack_a │\n");
	// 	printf("└───────────────┘\n");
	// 	printf("  * ** *** ** *  \033[0m\n");
	// 	return ;
	// }
	if (!stack_b)
	{
		printf("\033[1;34m\n\t\t\t┌───────────────┐\n");
		printf("\t\t\t│ Empty stack_b │\n");
		printf("\t\t\t└───────────────┘\n");
		printf("\t\t\t  * ** *** ** *  \033[0m\n");
	}
	printf("\n\n\033[1;91m─────────────────────────────────────────────────────────\033[1;34m\n\n");
	printf("\033[1;34m┌───────────────┐\t┌───────────────┐\n");
	printf("│    \033[1;34mStack A    \033[1;34m│\t");
	printf("│    \033[1;34mStack B    \033[1;34m│\n");
	printf("└───────────────┘\t└───────────────┘\n\033[1;34m");
	printf("\033[1;34m┌─────┬─────────┐\t┌─────┬─────────┐\n");
	printf("│ \033[1;91mInd \033[1;34m│  \033[1;37mValue  \033[1;34m│\t");
	printf("│ \033[1;91mInd \033[1;34m│  \033[1;37mValue  \033[1;34m│\n");
	printf("├─────┼─────────┤\t├─────┼─────────┤\n\033[0m");
	while (index < 10)
	{
		if (stack_a)
		{
			printf("\033[1;34m│ \033[\033[0;31m%2d  \033[1;34m│ \033[0m%5d   \033[1;34m│\t", index, stack_a->content);
			stack_a = stack_a->next;
		}
		else
			printf("\033[1;34m│     │         │\t");
		if (stack_b)
		{
			printf("│ \033[\033[0;31m%2d  \033[1;34m│ \033[0m%5d   \033[1;34m│\n", index, stack_b->content);
			stack_b = stack_b->next;
		}
		else
			printf("│     │         │\n");
		index++;
	}
	printf("└─────┴─────────┘\t└─────┴─────────┘\033[0m\n\n");
	printf("\033[1;91m─────────────────────────────────────────────────────────\033[1;91m\n\n");
	
}

void	print_move_and_size(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	printf("\t\033[1;34m┌─────────────────────────┐\n");
	printf("\t│      \033[1;91mCount move : %2i\033[1;34m    │\n", info->move);
	printf("\t└─────────────────────────┘\n");
	
	printf("\n\033\t[1;34m┌─────────────────────────┐\n");
	printf("\t│     \033[1;91mStack size : %3i\033[1;34m    │\n", info->size);
	printf("\t└─────────────────────────┘\n\n");
}