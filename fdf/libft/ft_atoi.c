/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:55:42 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/10/30 13:55:44 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	long	n;
	long	sign;

	sign = 1;
	n = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s <= '9' && *s >= '0')
	{
		n = (n * 10) + *s - '0';
		if (n > 922337203685477580 && *(s + 1))
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
		s++;
	}
	return ((int)(n * sign));
}
/*
#include <stdio.h>

int main(int ac, char **av)
{
	printf("%d\n", ft_atoi(av[1]));
	printf("->%d\n", atoi(av[1]));
}*/
