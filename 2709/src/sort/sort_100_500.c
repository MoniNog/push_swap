/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:14:15 by moni              #+#    #+#             */
/*   Updated: 2024/09/22 19:54:02 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

t_price *find_best_price(t_stack *a)
{
	t_stack *cheapest;

	cheapest = a;
	a = a->next;//pour pas comparer lepremier avec lui meme
	while (a)
	{
		if (cheapest->struct_price->price > a->struct_price->price)
			cheapest = a;
		a = a->next;
	}
	return(cheapest->struct_price);
}

t_stack *find_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}
#include <stdio.h>

// Définir des macros pour les couleurs
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

// 1er probleme : pour le new_min, il trouve pas forcement ou se glisser, ou se trouve le debut de liste

void calculate_price(t_stack *a, t_stack *b, t_info *info)
{
	int			stage_b;
	int			stage_a;
	int			test;
	stage_a = 0;
	//print_stack_big(a, 'a');
	//print_stack_big(b, 'b');
	//printf("┌─────┬─────┬─────┬─────┬──────┐\n");
	//printf("│ %-3s │ %-3s │ %-3s │ %-3s │ %-4s │\n", "nb", "$A", "-", "$B", "$$");
	//printf("├─────┼─────┼─────┼─────┼──────┤\n");

	while (get_stack_size(a) != 0)
	{
		t_stack *tmp = b;
		test = 0;
		stage_b = 0;
		int b_max = find_max(tmp);
		int b_min = find_min(tmp);
		if (a->content > b->content && a->content < find_last(b)->content)
			test = 1;
		else if (a->content > b_max)
		{
			//printf("%i - %i\n", a->content, b_max);
			stage_b = find_max_index(tmp);
			test = 2;
		}
		else if (a->content < b_min)
		{
			//printf("%i - %i\n", a->content, b_max);
			stage_b = find_min_index(tmp) + 1;
			test = 3;
		}
		else
		{
			test = 4;
			while (tmp->next && !(a->content < tmp->content && a->content > tmp->next->content))
			{
				//printf("nbr: %i - a: %i - a->next: %i\n", a->content, tmp->content, tmp->next->content);
				stage_b++;
				tmp = tmp->next;
			}
			stage_b++;
		}
		if (test != 0)
			test = 0;

		// Calculate the price based on stage_a and stage_b
		if (stage_b >= stage_a)
			a->struct_price->price = stage_b;
		else
			a->struct_price->price = stage_a;

		a->struct_price->a_price = stage_a;
		a->struct_price->b_price = stage_b;

		// Print the step for debugging
		//printf("│ %-3i │ %-3i │     │ %-3i │ %-4i │ %-5i\n", a->content, stage_a, stage_b, a->struct_price->price, test);

		// Move to the next element in A
		a = a->next;
		stage_a++;
	}

	// Ligne de fin du tableau
	//printf("└─────┴─────┴─────┴─────┴──────┘\n");
}

void initialize_struct_price(t_stack *stack)
{
    while (stack)
    {
        stack->struct_price = malloc(sizeof(t_price));
        if (!stack->struct_price)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        stack->struct_price->price = 0;
        stack->struct_price->a_price = 0;
        stack->struct_price->b_price = 0;
        stack = stack->next;
    }
}

void	sort_100_500(t_stack **a, t_stack **b, t_info *info)
{
	pb(a, b, info);
	pb(a, b, info);

	initialize_struct_price(*a);

	while(get_stack_size(*a))
	{
		//printf("Total A: %i\n", get_stack_size(*a));
		calculate_price(*a, *b, info);
		t_price	*cheapest = find_best_price(*a);
		//printf("%i - %i - %i\n", cheapest->price, cheapest->a_price, cheapest->b_price);

		while (cheapest->a_price > 0 && cheapest->b_price > 0)
		{
			rr(a, b, info);
			cheapest->a_price--;
			cheapest->b_price--;
		}
		while(cheapest->a_price > 0)
		{
			ra(a, info);
			cheapest->a_price--;
		}
		while(cheapest->b_price > 0)
		{
			rb(b, info);
			cheapest->b_price--;
		}
		pb(a, b, info);
		//print_stack_big(*a, 'a');
		//print_stack_big(*b, 'b');
	}
	//write(1, "-----\n", 6);
	
	while((*b)->content != find_max(*b))
	{
		rb(b, info);
	}
	while(*b)
	{
		pa(a, b, info);
	}
}
