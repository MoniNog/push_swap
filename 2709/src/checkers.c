/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 08:56:18 by moni              #+#    #+#             */
/*   Updated: 2024/09/09 14:55:55 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

bool	is_int(long number)
{
	if (number >= INT_MIN && number <= INT_MAX)
		return (true);
	return (false);
}

bool	checks_are_ok(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] >= '0' && av[i] <= '9') || av[i] == ' ' || av[i] == '\t'
			|| av[i] == '\n' || av[i] == '\r' || av[i] == '\v'
			|| av[i] == '\f' || av[i] == '-')
		{
			if (av[i] == '-' && (av[i + 1] < '0' || av[i + 1] > '9'))
			{
				write(2, "Error\n", 6);
				return (false);
			}
		}
		else
		{
			write(2, "Error\n", 6);
			return (false);
		}
		i++;
	}
	return (true);
}

int	count_len_word(const char *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

int	count_words(const char *s, char c)
{
	int	n_word;
	int	i;

	n_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			n_word++;
		i++;
	}
	return (n_word);
}
