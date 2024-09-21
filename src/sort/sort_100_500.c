/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:14:15 by moni              #+#    #+#             */
/*   Updated: 2024/09/21 16:17:46 by moni             ###   ########.fr       */
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
	t_stack		*top_b;
	int			stage_a;

	stage_a = 0;
	top_b = b;

	// En-tête du tableau avec séparateurs
	printf("┌─────┬─────┬─────┬─────┬──────┐\n");
	printf("│ %-3s │ %-3s │ %-3s │ %-3s │ %-4s │\n", "nb", "$A", "-", "$B", "$$");
	printf("├─────┼─────┼─────┼─────┼──────┤\n");

	while (a)
	{
		b = top_b;
		stage_b = 0;
		const char *min_max_flag = "";  // Pour spécifier "min" ou "max"

		if (a->content < find_min(b, info))
		{
			while (b->content == b->max_index)
			{	
				stage_b++;
				b = b->next;
			}
			min_max_flag = RED "min" RESET;
		}
		else if (a->content > find_max(b))
		{		
			while (b->next && b->content != b->max_index)
			{
				stage_b++;
				b = b->next;
			}
			min_max_flag = BLUE "max" RESET;
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
				}
		}
		if (stage_b >= stage_a)
			a->price = stage_b;
		else
			a->price = stage_a;

		// Affichage du contenu sous forme de tableau avec lignes de séparation et couleurs
		printf("│ %-3i │ %-3i │     │ %-3i │ %-4i │ %s\n", a->content, stage_a, stage_b, a->price, min_max_flag);

		// Séparation entre les lignes pour mieux visualiser chaque étape
		printf("├─────┼─────┼─────┼─────┼──────┤\n");

		a = a->next;
		stage_a++;
	}

	// Ligne de fin du tableau
	printf("└─────┴─────┴─────┴─────┴──────┘\n");
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

