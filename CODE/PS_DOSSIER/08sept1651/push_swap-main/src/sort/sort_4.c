/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:20:49 by moni              #+#    #+#             */
/*   Updated: 2024/09/08 20:21:05 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"


void sort_4(t_stack **a, t_stack **b, t_info *info)
{
	
	
	if (info->min_index == 0)
	{
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return;
	}
	else if (info->min_index == 1)
	{
		ra(a, info);
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return;
	}
	else if (info->min_index == 2)
	{
		rra(a, info);
		rra(a, info);
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return;
	}
	else if (info->min_index == 3)
	{
		rra(a, info);
		pb(a, b, info);
		sort_3(a, b, info);
		pa(a, b, info);
		return;
	}
}

// void sort_4(t_stack **a, t_stack **b, t_info *info)
// {
	
	
// 	if (info->min_index == 0)
// 	{
// 		pb(a, b, info);
// 		sort_3(a, b, info);
// 		pa(a, b, info);
// 		return;
// 	}
// 	else if (info->min_index == 1)
// 	{
// 		ra(a, info);
// 		pb(a, b, info);
// 		sort_3(a, b, info);
// 		pa(a, b, info);
// 		return;
// 	}
// 	else if (info->min_index == 2)
// 	{
// 		rra(a, info);
// 		rra(a, info);
// 		pb(a, b, info);
// 		sort_3(a, b, info);
// 		pa(a, b, info);
// 		return;
// 	}
// 	else if (info->min_index == 3)
// 	{
// 		rra(a, info);
// 		pb(a, b, info);
// 		sort_3(a, b, info);
// 		pa(a, b, info);
// 		return;
// 	}
// }

// void	execute_operations(char *operations)
// {
// 	// Fonction qui va exécuter les opérations
// 	// Exemple : "sa ra pa" -> exécuter sa(); ra(); pa();
// 	printf("Executing operations: %s\n", operations);
// }

// void	sort_permutation(int stack[4])
// {
// 	int		i;
// 	int		j;
// 	int		match;

// 	i = 0
// 	j = 0;
// 	match = 1;

// 	while (i < 24)
// 	{
// 		printf("Permutation: %d %d %d %d, Operations: %s\n",
// 			sort_cases[i].permutation[0],
// 			sort_cases[i].permutation[1],
// 			sort_cases[i].permutation[2],
// 			sort_cases[i].permutation[3],
// 			sort_cases[i].operations);
// 			i++;
// 	}
// 	while (j < 4)
// 	{
// 		if (stack[j] != sort_cases[i].permutation[j])
// 		{
// 			match = 0;
// 			break;
// 		}
// 		j++;
// 	}
// 	if (match)
// 	{
// 		execute_operations(sort_cases[i].operations);
// 		break;
// 	}
// }
