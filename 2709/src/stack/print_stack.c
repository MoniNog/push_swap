/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:52:37 by moni              #+#    #+#             */
/*   Updated: 2024/09/18 20:10:24 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

#define RED "\033[1;91m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

void	print_stack(t_stack* stack_a, t_stack* stack_b, t_info* info)
{
	int index;

	index = 0;
	// Affichage principal
	printf(RED "\n─────────────────────────────────────────────────────────" BLUE "\n");
	printf(BLUE "┌───────────────┐\t┌───────────────┐\n");
	printf("│    Stack A    │\t│    Stack B    │\n");
	printf("└───────────────┘\t└───────────────┘\n");
	printf("┌─────┬─────────┐\t┌─────┬─────────┐\n");
	printf("│" RED " Ind " BLUE "│  Value  │\t│" RED " Ind " BLUE "│" "  Value  " BLUE "│\n");
	printf("├─────┼─────────┤\t├─────┼─────────┤\n" RESET);

	// Affiche les éléments des piles tant qu'ils existent
	while (index < info->size)
	{
		if (stack_a)
		{
			// Affichage bien aligné pour Stack A
			printf(BLUE "│ " RED "%2d  " BLUE "│ %5d\t│\t", index, stack_a->content);
			stack_a = stack_a->next;
		}
		else
			// Si Stack A est vide, on affiche des espaces pour garder l'alignement
			printf(BLUE "│     │         │\t");

		if (stack_b)
		{
			// Affichage bien aligné pour Stack B
			printf("│ " RED "%2d  " BLUE "│" RED "%5d\t" BLUE "│\n", index, stack_b->content);
			stack_b = stack_b->next;
		}
		else
			// Si Stack B est vide, on affiche des espaces pour garder l'alignement
			printf("│     │         │\n");

		index++;
	}
	
	printf("└─────┴─────────┘\t└─────┴─────────┘" RESET "\n");
	printf(RED "─────────────────────────────────────────────────────────" RESET "\n");
}

void	print_move_and_size(t_stack* stack_a, t_stack* stack_b, t_info* info)
{
	printf("\t" BLUE "┌─────────────────────────┐\n");
	printf("\t│" RED "    Count move : %3i" BLUE "     │\n", info->move);
	printf("\t└─────────────────────────┘\n");

	printf("\n\t" BLUE "┌─────────────────────────┐\n");
	printf("\t│" RED "    Stack size : %3i" BLUE "     │\n", info->size);
	printf("\t└─────────────────────────┘\n\n");
}
