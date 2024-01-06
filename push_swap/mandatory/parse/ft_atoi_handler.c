/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:49:31 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/06 00:52:09 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi_handler(const char *s, int *nbr)
{
	long	n;
	long	sign;

	sign = 1;
	n = 0;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
		if (*s < '0' || *s > '9' )
			return (0);
	}
	while (*s)
	{
		if (*s > '9' || *s < '0')
			return (0);
		if (sign > 0 && n >= 214748364 && *s - '0' > 7)
			return (0);
		if (sign < 0 && n >= 214748364 && *s - '0' > 8)
			return (0);
		n = (n * 10) + *s - '0';
		s++;
	}
	return (*nbr = (int)(n * sign), 1);
}
