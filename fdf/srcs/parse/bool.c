/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:47:52 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/26 13:47:52 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ternary(int boolean, int a, int b)
{
	return ((boolean * a) + (!boolean * b));
}

int	in_hexa(char c)
{
	return (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e'
		|| c == 'f' || c == 'A' || c == 'B' || c == 'C' || c == 'D'
		|| c == 'E' || c == 'F' || c == 'x' || c == ',' || c == '-'
		|| c == '+');
}

int	is_all_num(char *str)
{
	while (*str && *str != '\n')
	{
		while (*str && *str == ' ')
			str++;
		if (*str && *str < '0' && *str > '9' && !in_hexa(*str))
			return (printf("%c\n",*str), 0);
		if (*str)
			str++;
	}
	return (1);
}

int	valid_extention(char *av)
{
	char	*s;

	s = NULL;
	if (av)
		s = ft_strrchr(av, '.');
	if (s && !ft_strncmp(s + 1, "fdf", 3))
		return (1);
	return (0);
}
