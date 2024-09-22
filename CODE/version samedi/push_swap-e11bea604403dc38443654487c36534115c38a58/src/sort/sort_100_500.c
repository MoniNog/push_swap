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
	t_stack		*top_b;
	int			stage_a;

	stage_a = 0;
	top_b = b;

	printf("┌─────┬─────┬─────┬─────┬──────┐\n");
	printf("│ %-3s │ %-3s │ %-3s │ %-3s │ %-4s │\n", "nb", "$A", "-", "$B", "$$");
	printf("├─────┼─────┼─────┼─────┼──────┤\n");

	while (a)
	{
		b = top_b;
		stage_b = 0;
		const char *min_max_flag = "";  // Pour spécifier "min" ou "max"


		if (a->content > find_max(b) || a->content < find_min(b))
		{
			stage_b = 1;
			while (b->next && b->content < b->next->content)
			{	
				stage_b++;
				b = b->next;
			}
			min_max_flag = RED "min ou max" RESET;
		}
		else
		{
			if (a->content > b->content && a->content < find_last(b)->content)
				stage_b = 0;
			else 
				while (b->next && b->next && !(a->content < b->content && a->content > b->next->content))
				{
					stage_b++;
					b = b->next;
				}
		}
		if (stage_b >= stage_a)
			a->struct_price->price = stage_b;
		else
			a->struct_price->price = stage_a;
		write(1, "lily\n", 5);
		a->struct_price->a_price = stage_a;
		a->struct_price->b_price = stage_b;

		// Affichage du contenu sous forme de tableau avec lignes de séparation et couleurs
		printf("│ %-3i │ %-3i │     │ %-3i │ %-4i │ %s\n", a->content, stage_a, stage_b, a->struct_price->price, min_max_flag);

		// Séparation entre les lignes pour mieux visualiser chaque étape
		printf("├─────┼─────┼─────┼─────┼──────┤\n");

		a = a->next;
		stage_a++;
	}

	// Ligne de fin du tableau
	printf("└─────┴─────┴─────┴─────┴──────┘\n");
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

void	sort_100_500(t_stack **a, t_stack **b, t_info *info)
{
	pb(a, b, info);
	pb(a, b, info);

	initialize_struct_price(*a);
	calculate_price(*a, *b, info);
	// t_price	*cheapest = find_best_price(*a);
	// printf("%i - %i - %i\n", cheapest->price, cheapest->a_price, cheapest->b_price);
}
