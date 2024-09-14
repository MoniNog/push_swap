/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:19:34 by moni              #+#    #+#             */
/*   Updated: 2024/09/14 21:23:51 by moni             ###   ########.fr       */
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

	// si ac > 2 ne pas utiliser split 
	// si ac = 2 utiliser split

	// ./pushswap 1 5 2 3
	// ./pushswap "1 5 2   	 3"
	int i = 0;
	// if (ac > 1 && checks_are_ok(av[1]) == true)
	if (ac < 2)
		return (0);
	if (ac == 2) {
		z = split(av[1], ' ');
		while (z[i])
		{
			printf("|%s|\n", z[i]);
			i++;
		}
		i++;
	} else {
		z = (av + 1); // ^= &av[i]
		printf("%d", ft_strlen(z));
		i = ac;
	}

	create_stack(&stack_a, &stack_b, &info, ac, z);// !! ici pour les arg
	print_stack(stack_a, stack_b, info);
	choose_sort(&stack_a, &stack_b, info);
	print_stack(stack_a, stack_b, info);
	print_move_and_size(stack_a, stack_b, info);
	//	implicitement, si pas d'argument ou un seul argument
	//	il ne se passe rien.

	free(info);
	free_stack(stack_a);

	return (0);
}