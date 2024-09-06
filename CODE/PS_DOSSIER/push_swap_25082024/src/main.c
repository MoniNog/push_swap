/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:19:34 by moni              #+#    #+#             */
/*   Updated: 2024/09/06 10:54:58 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	int			index;

	(void)info;
	index = 0;
	if (!stack_a)
	{
		printf("\033[1;34m┌───────────────┐\n");
		printf("│  \033[0;33mEmpty stack  \033[1;31m│\n");
		printf("└───────────────┘\n");
		printf("  * ** *** ** *  \033[0m\n");
		return;
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
	while (index < info->size)
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

// int		find_min(t_stack *stack)
// {
// 	int		min;
	
// 	min = stack->content;
// 	while (stack->next)// besoin de 2 pour comparer
// 	{
// 		if (min > stack->next->content)
// 			min = stack->next->content;
// 		stack = stack->next;
// 	}
// 	return(min);
// }

// int		find_max(t_stack *stack)
// {
// 	int		max;
	
// 	max = stack->content;
// 	while (stack->next)// besoin de 2 pour comparer
// 	{
// 		if (max < stack->next->content)
// 			max = stack->next->content;
// 		stack = stack->next;
// 	}
// 	return(max);
// }

// void	tri_tree(t_stack **a, t_stack **b, t_info *info)
// {
// 	int		min = find_min(*a);
// 	int		max = find_max(*a);
// 	if ((*a)->content == min)
// 	{
// 		if ((*a)->next->content < (*a)->next->next->content)// 1 2 3
// 			return ;
// 		else// 1 3 2
// 		{
// 			rra(a, info);// 1 3 2
// 			sa(a, info);
// 			return ;
// 		}
// 	}
// 	else if ((*a)->content == max)// 321 312
// 	{
// 		if ((*a)->next->content == min)// 312
// 		{
// 			ra(a, info);
// 			return ;
// 		}
// 		else//321
// 		{
// 			ra(a, info);
// 			sa(a, info);
// 			return ;
// 		}
// 	}
// 	else if ((*a)->next->content == min)// 213
// 	{
// 		rra(a, info);
// 		sa(a, info);
// 		return ;
// 	}
// 	else if ((*a)->next->content != min)// 231
// 	{
// 		rra(a, info);
// 		return;
// 	}
// 	else
// 		return;
// }

void	creat_stack(t_stack *stack_a, t_stack *stack_b, int ac, char **av)
{
	t_stack	*new_number;
	int		i;
	t_info	*info;
	t_stack	*a = stack_a;
	t_stack	*b = stack_b;

	info = malloc(sizeof(t_info));
	if (info == NULL) 
		return ;
	info->move = 0;
	info->size = 0;
	a = new_node(av[1], info);
	i = 2;
	while (i < ac)
	{
		new_number = new_node(av[i], info);
		if (new_number)
			push_back(&stack_a,new_number);
		i++;
	}
	print_stack(a, b, info);

	tri(&a, &b, info);
	// int stack[4] = {4, 3, 2, 1};
	// sort_permutation(a);
	
	printf("\033[1;34m┌─────────────────────┐\n");
	printf("│                     │\n");
	printf("│   \033[1;91mCount move : %3i\033[1;34m  │\n", info->move);
	printf("│                     │\n");
	printf("└─────────────────────┘\n");
	
	printf("\n\033[1;34m┌─────────────────────┐\n");
	printf("│                     │\n");
	printf("│   \033[1;91mStack size : %2i\033[1;34m   │\n", info->size);
	printf("│                     │\n");
	printf("└─────────────────────┘\n\n");

	free(info);
	free_stack(a);
	free_stack(b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	if (ac > 1)
		creat_stack(stack_a, stack_b, ac, av);

	return (0);
}

// pas de doublons - eror
// limites du int - eror
// digit - eror
// split " "
// Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre
//		l’invite de commande.
