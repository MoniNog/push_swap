/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:14:15 by moni              #+#    #+#             */
/*   Updated: 2024/09/20 12:32:32 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

t_stack *find_best_price(t_stack *a)
{
	t_stack *cheapest;

	cheapest = a;
	a = a->next;//pour pas comparer lepremier avec lui meme
	while (a)
	{
		if (cheapest->price > a->price)
			cheapest = a;
		a = a->next;
	}
	printf("%i", cheapest->content);
	return(cheapest);
}

t_stack *find_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	calculate_price(t_stack *a, t_stack *b, t_info *info)
{
	int			stage_b;
	t_stack		*top_b;
	int			stage_a;

	stage_a = 0;
	top_b = b;//repere pour le haut de la stack b
	while(a)// parcourir tous les element de la stack a
	{
		b = top_b;
		stage_b = 1;
        // suis je dans un cas ou a et un nouveau min ou un nouveau max ?
		if (a->content < find_min(b, info))
		{
			printf("%i = min // price : %i\n", a->content, stage_a);
			a->price = stage_a;
			// a->stage_b = ...;
			// while (a->content )

		}
		else if (a->content > find_max(b))
		{		
			a->price = stage_a;
			printf("%i = max // price : %i\n", a->content, stage_a);
		}
		else 
		{
			if (a->content > b->content && a->content < find_last(b)->content)
				stage_b = 0;
			else 
				while (b->next && !(a->content < b->content && a->content > b->next->content))
				{
					stage_b++;
					b = b->next;
					// a->stage_b = stage_b;
				}
			if (stage_b >= stage_a)
				a->price = stage_b;
			else
				a->price = stage_a;

			printf("price de %i = (stage_b = %i // STAGE = %i) %i\n", a->content, stage_b, stage_a, a->price);
		}
		a = a->next;// change de nombre a
		
		// a->stage_a = stage_a;
		stage_a++;
	}
}

// sequence
// {
	
// }


// STEPS :
// determiner stage b si min ou max
//		checker
// void creer_seq()avec stage a et stage b
// 		check si seq sexecute correctement et comme prevu et logique
// void executer_seq() 
// ev changer terme stack
    
// // 	stage_b = 


// 	if (stage_b > etage de n_a depuis le haut)
// 		price = etage de n_a depuis le haut;
// 		//sequence = rrr * stage_b + ra ou rb ?? * etage de na - stage_b...
// 	else
// 		price = stage_b;
// 		//sequence = rrr * stage_b;


// 	si a[1] se toruve ua milieu
// 		pb
// 		placement
// 	rr jusqua

// 	rr tant que les nombres cote a et b ne sont pas alligne



// 	si mon nombre a[1] est le nouveau max de b 
// 	si mon nombre a[1] 
// }

// do_move

