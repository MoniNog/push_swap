/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:52:37 by moni              #+#    #+#             */
/*   Updated: 2024/09/14 19:52:11 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

#define RED "\033[1;91m"
#define BLUE "\033[1;34m"

void	print_stack(t_stack* stack_a, t_stack* stack_b, t_info* info)
{
	int index;

	index = 0;

	if (!stack_b)
	{
		printf(BLUE "\n\t\t\t┌───────────────┐\n");
		printf("\t\t\t│ Empty stack_b │\n");
		printf("\t\t\t└───────────────┘\n");
		printf("\t\t\t  * ** *** ** *  \033[0m\n");
	}

	printf(RED "\n\n─────────────────────────────────────────────────────────" BLUE "\n\n");
	printf(BLUE "┌───────────────┐\t┌───────────────┐\n");
	printf("│    Stack A    │\t│    Stack B    │\n");
	printf("└───────────────┘\t└───────────────┘\n");
	printf("┌─────┬─────────┐\t┌─────┬─────────┐\n");
	printf("│" RED " Ind " BLUE "│"  RED "  Value"  BLUE "|\t│" RED " Ind " BLUE "│" "  Value  " BLUE "│\n");
	printf("├─────┼─────────┤\t├─────┼─────────┤\n\033[0m");

	while (index < 10)
	{
		if (stack_a)
		{
			printf(BLUE "│ " RED "%2d  " BLUE "│ " RED "%5d" BLUE " │\t", index, stack_a->content);
			stack_a = stack_a->next;
		}
		else
			printf(BLUE "│     │         │\t");

		if (stack_b)
		{
			printf("│ " RED "%2d  " BLUE "│ " RED "%5d" BLUE " │\n", index, stack_b->content);
			stack_b = stack_b->next;
		}
		else
			printf("│     │         │\n");

		index++;
	}
	
	printf("└─────┴─────────┘\t└─────┴─────────┘\033[0m\n\n");
	printf(RED "─────────────────────────────────────────────────────────" RED "\n\n");
}

void	print_move_and_size(t_stack* stack_a, t_stack* stack_b, t_info* info)
{
	printf("\t" BLUE "┌─────────────────────────┐\n");
	printf("\t│" RED " Count move : %2i" BLUE "    │\n", info->move);
	printf("\t└─────────────────────────┘\n");

	printf("\n\t" BLUE "┌─────────────────────────┐\n");
	printf("\t│" RED " Stack size : %3i" BLUE "    │\n", info->size);
	printf("\t└─────────────────────────┘\n\n");
}
