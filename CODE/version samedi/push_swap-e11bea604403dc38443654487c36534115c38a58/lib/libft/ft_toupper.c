/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:33:43 by moni              #+#    #+#             */
/*   Updated: 2024/05/27 17:48:46 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// minuscule en majuscule 		a -> A

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		c = c - 32;
	return (c);
}
