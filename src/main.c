/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:19:34 by moni              #+#    #+#             */
/*   Updated: 2024/09/07 15:40:57 by moni             ###   ########.fr       */
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
	

	if (ac > 1)
	{
		create_stack(&stack_a, &stack_b, &info, ac, av);
		tri_three(&stack_a, &stack_b, info);
		print_stack(stack_a, stack_b, info);
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
