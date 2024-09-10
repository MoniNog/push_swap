/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:19:34 by moni              #+#    #+#             */
/*   Updated: 2024/09/09 20:23:56 by moni             ###   ########.fr       */
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

	if (ac > 1 && checks_are_ok(av[1]) == true)
	{
		create_stack(&stack_a, &stack_b, &info, ac, av);
		// print_stack(stack_a, stack_b, info);  // print the stack after creation
		choose_sort(&stack_a, &stack_b, info);
		// print_stack(stack_a, stack_b, info);  // print the stack after sorting
		// print_move_and_size(stack_a, stack_b, info);
	}
	//	implicitement, si pas d'argument ou un seul argument
	//	il ne se passe rien.

	(info);
	free_stack(stack_a);

	return (0);
}