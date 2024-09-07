/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:19:34 by moni              #+#    #+#             */
/*   Updated: 2024/09/07 17:38:18 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;

	stack_a = NULL;
	stack_b = NULL;
	info = NULL;

	if (ac > 1)
	{
			printf("\navant tout...\n");
			print_stack(stack_a, stack_b, info);

			printf("\ncreate_stack\n");
		create_stack(&stack_a, &stack_b, &info, ac, av);
			print_stack(stack_a, stack_b, info);

			printf("\nsort\n\n");
		// sort_all(&stack_a, &stack_b, info);
		sort_3(&stack_a, &stack_b, info);
			print_stack(stack_a, stack_b, info);
			
			printf("\nmove and size\n");
			print_move_and_size(stack_a, stack_b, info);
			
			printf("\nend\n");
	}
	
	
	free(info);
	free_stack(stack_a);
	free_stack(stack_b);
	
	return (0);
}

// pas de doublons - eror
// limites du int - eror
// digit - eror
// split " "
// Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre
//		l’invite de commande.
