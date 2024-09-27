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
	a = a->next;//pour pas comparer le premier avec lui meme
	while (a)
	{
		if (cheapest->struct_price->price > a->struct_price->price)
			cheapest = a;
		a = a->next;
	}
	return(cheapest->struct_price);
}

void	store_prices(t_stack *a, int stage_a, int stage_b)
{
	if (stage_b > stage_a)
		a->struct_price->price = stage_b;
	else
		a->struct_price->price = stage_a;
	a->struct_price->a_price = stage_a;
	a->struct_price->b_price = stage_b;
}

void calculate_price(t_stack *a, t_stack *b, t_info *info)
{
	int			stage_b;
	int			stage_a;
	
	stage_a = 0;
	while (get_stack_size(a) != 0)
	{
		t_stack *tmp = b; // permet de parcourir stack b sans perdre de vue le ptr sur le 1er element
		stage_b = 1;
		int b_max = find_max(tmp); // nombre max de b
		int b_min = find_min(tmp); // nombre min de b
		if (a->content > b_max || a->content < b_min) // element a devient le nouveau max/min de b
			stage_b = find_max_index(tmp); // trouve la position entre min|max dans stack b
		else
		{
			while (tmp->next && !(a->content < tmp->content && a->content > tmp->next->content))
			//					![a < b && a > b+1]	-> on s'arrete quand cette condition est ok ! :)
			{
				stage_b++;
				tmp = tmp->next;
			}
		}
		store_prices(a, stage_a, stage_b);
		a = a->next;
		stage_a++; // calcule le prix pour l'element suivant
	}
}

void	rotate_stack(t_stack **a, t_stack **b, t_info *info, t_price *cheapest)
{
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
}

void	sort_100_500(t_stack **a, t_stack **b, t_info *info)
{
	pb(a, b, info);
	pb(a, b, info);
	initialize_struct_price(*a); //malloc prices
	while(get_stack_size(*a))
	{
		calculate_price(*a, *b, info);
		t_price	*cheapest = find_best_price(*a);
		rotate_stack(a, b, info, cheapest);
		pb(a, b, info);
	}
	if (find_max_index(*b) > (get_stack_size(*b) / 2))
	{
		while((*b)->content != find_max(*b))
			rrb(b, info);
	}
	else
	{
		while((*b)->content != find_max(*b))
			rb(b, info);
	}
	while(*b)
		pa(a, b, info);
}
