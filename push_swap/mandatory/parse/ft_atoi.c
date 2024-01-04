/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:16:44 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/04 12:01:43 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *s, int *nbr)
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
