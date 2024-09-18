/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:14:15 by moni              #+#    #+#             */
/*   Updated: 2024/09/18 21:17:19 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	sort_b(t_stack **b, t_info *info)
{
	if ((*b)->content < (*b)->next->content)
		sb(b, info);
}

void	calculate_price(t_stack *a, t_stack *b, t_info *info)
{
	int			count;
	t_stack		*top_b;
	int			stage_a;

	stage_a = 0;
	top_b = b;//repere pour le haut de la stack b
	sort_b(&b, info);
	while(a->next)// parcourir tous les element de la stack a
	{
		b = top_b;
		count = 1;
        // suis je dans un cas ou a et un nouveau min ou un nouveau max ?
		if (a->content < find_min(b, info))
		{
			//printf("%i = min\n", a->content);
			rrb(&b, info);
			pb(&a, &b, info);
			rb(&b, info);
		}
		else if (a->content > find_max(b))
		{		
			pb(&a, &b, info);
			//printf("%i = max\n", a->content);
		}
		else 
		{


			while (!(a->content < b->content && a->content > b->next->content))
			{
				count++;
				if (b->next)
					b = b->next;
			}
			
			if (count >= stage_a)
				a->price = count;
			else
				a->price = -stage_a;
		
			printf("price de %i = (COUNT = %i // STAGE = %i) %i\n", a->content, count, stage_a, a->price);
		}
			stage_a++;
			if (a->next)
				a = a->next;// change de nombre a
	}
}


// STEPS :
// soccuper du cas où a est le mini ou max de stack_b :)
// 	check mais attention etape suivante nec pour bien checker
// void trouver min price dans stack_a
// 	check si les prix sont correctes
// void creer_seq()
// 	check si seq sexecute correctement et comme prevu et logique
// void executer_seq() 
    
// // 	count = 


// 	if (count > etage de n_a depuis le haut)
// 		price = etage de n_a depuis le haut;
// 		//sequence = rrr * count + ra ou rb ?? * etage de na - count...
// 	else
// 		price = count;
// 		//sequence = rrr * count;


// 	si a[1] se toruve ua milieu
// 		pb
// 		placement
// 	rr jusqua

// 	rr tant que les nombres cote a et b ne sont pas alligne



// 	si mon nombre a[1] est le nouveau max de b 
// 	si mon nombre a[1] 
// }

// do_move

