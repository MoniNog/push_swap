/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:19:34 by moni              #+#    #+#             */
/*   Updated: 2024/08/29 13:15:42 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int			index;

	index = 0;
	if (!stack_a)
	{
		// printf("\033[1;34m┌───────────────┐\n");
		// printf("│  \033[0;33mEmpty stack  \033[1;31m│\n");
		// printf("└───────────────┘\n");
		// printf("  * ** *** ** *  \033[0m\n");
		return;
	}
	printf("\033[1;34m\n┌───────────────┐\t┌───────────────┐\n");
	printf("│    \033[1;34mStack A    \033[1;34m│\t");
	printf("│    \033[1;34mStack B    \033[1;34m│\n");
	printf("└───────────────┘\t└───────────────┘\n\033[1;34m");
	printf("\033[1;34m┌─────┬─────────┐\t┌─────┬─────────┐\n");
	printf("│ \033[1;91mInd \033[1;34m│  \033[1;37mValue  \033[1;34m│\t");
	printf("│ \033[1;91mInd \033[1;34m│  \033[1;37mValue  \033[1;34m│\n");
	printf("├─────┼─────────┤\t├─────┼─────────┤\n\033[0m");
	while (index <= 5)
	{
		if (stack_a)
		{
			printf("\033[1;34m│ \033[\033[0;31m%2d  \033[1;34m│ \033[0m%5d   \033[1;34m│\t", index, stack_a->content);
			stack_a = stack_a->next;
		}
		else
			printf("│     │         │\t");
		if (stack_b)
		{
			printf("│ \033[\033[0;31m%2d  \033[1;34m│ \033[0m%5d   \033[1;34m│\n", index, stack_b->content);
			stack_b = stack_b->next;
		}
		else
			printf("│     │         │\n");
		index++;
	}
	printf("└─────┴─────────┘\t└─────┴─────────┘\033[0m\n");
}

void	creat_stack(t_stack *stack_a, t_stack *stack_b, int ac, char **av)
{
	t_stack	*new_number;
	int		i;

	stack_a = new_node(av[1]);
	i = 2;
	while (i < ac)
	{
		new_number = new_node(av[i]);
		if (new_number)
			push_back(&stack_a,new_number);
		i++;
	}
	print_stack(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	if (ac > 1)
		creat_stack(stack_a, stack_b, ac, av);
	free_stack(stack_a);
	free_stack(stack_b);
	
	return (0);
}
