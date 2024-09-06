/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:04:06 by monoguei          #+#    #+#             */
/*   Updated: 2024/09/03 18:23:28 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// verifie si un entier est un caractere numerique

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);// digit
	return (1);//
}
