/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 09:39:18 by moni              #+#    #+#             */
/*   Updated: 2024/09/22 09:52:50 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/pushswap.h"

// Définir des macros pour les couleurs
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

// Fonction pour initialiser struct_price pour chaque élément de la pile
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

t_price *find_best_price(t_stack *a)
{
    t_stack *cheapest;

    cheapest = a;
    a = a->next; // pour ne pas comparer le premier avec lui-même
    while (a)
    {
        if (cheapest->struct_price->price > a->struct_price->price)
            cheapest = a;
        a = a->next;
    }
    return (cheapest->struct_price);
}

t_stack *find_last(t_stack *stack)
{
    while (stack->next)
        stack = stack->next;
    return (stack);
}

void calculate_price(t_stack *a, t_stack *b, t_info *info)
{
    int stage_b;
    t_stack *top_b;
    int stage_a;

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
                while (b->next && !(a->content < b->content && a->content > b->next->content))
                {
                    stage_b++;
                    b = b->next;
                }
        }

        if (stage_b >= stage_a)
            a->struct_price->price = stage_b;
        else
            a->struct_price->price = stage_a;

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

void sort_100_500(t_stack **a, t_stack **b, t_info *info)
{
    pb(a, b, info);
    pb(a, b, info);

    // Initialiser struct_price pour chaque élément de la pile a
    initialize_struct_price(*a);

    calculate_price(*a, *b, info);
    // t_price *cheapest = find_best_price(*a);
	free((*a)->struct_price);
	// free((*b)->struct_price);

}