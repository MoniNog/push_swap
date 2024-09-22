/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:19:34 by moni              #+#    #+#             */
/*   Updated: 2024/09/22 09:44:29 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;
	char **z;


	stack_a = NULL;
	stack_b = NULL;
	info = NULL;
	if (checks_are_ok(av[1]) == true && ac > 1)
	{
		if (ac == 2)
		{
			av[1] = clean_whitespace(av[1]);
			z = split(av[1], ' ');
		}
		else
			z = av + 1;// z devient le premier arg apres le nom du programme
		create_stack(&stack_a, &stack_b, &info, ac, z);
		replace_with_indices(&stack_a);
		choose_sort(&stack_a, &stack_b, info);
		print_stack(stack_a, stack_b, info);

		// pb(&stack_a, &stack_b, info);
		// pb(&stack_a, &stack_b, info);
		// pb(&stack_a, &stack_b, info);
		// pb(&stack_a, &stack_b, info);
		// print_stack(stack_a, stack_b, info);
		// calculate_price(stack_a, stack_b, info);
		// find_best_price(stack_a);
	
		print_stack(stack_a, stack_b, info);
		print_move_and_size(stack_a, stack_b, info);

		if (stack_b)
			free_stack(stack_b);
		free(info);
		free_stack(stack_a);
	}
	return (0);
}
