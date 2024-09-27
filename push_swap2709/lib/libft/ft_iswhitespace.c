/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:04:12 by monoguei          #+#    #+#             */
/*   Updated: 2024/09/11 09:39:46 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// verifie si un entier est un caracter de type "espace blanc"

int	ft_iswhitespace(int c)
{
	if (!(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
			|| c == '\f'))
		return (0);//pas un whitespace
	return (1);//whitespace
}
