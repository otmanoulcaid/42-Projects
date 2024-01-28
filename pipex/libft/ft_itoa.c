/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:10:51 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/10/31 16:46:44 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long n)
{
	if (n == 0)
		return (0);
	else if (n < 0)
		return (1 + len(n * -1));
	return (1 + len(n / 10));
}

static char	*get_str(long l, int s)
{
	char	*str;

	if (l == 0)
		s++;
	str = (char *)malloc((s + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (l == 0)
		*str = '0';
	else if (l < 0)
	{
		*str = '-';
		l *= -1;
	}
	*(str + s--) = '\0';
	while (l > 0)
	{
		*(str + s--) = l % 10 + 48;
		l /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	l;

	l = n;
	return (get_str(l, len(l)));
}
/*
#include <stdio.h>

int	main (int arc , char **arv)
{
	printf("%s\n", ft_itoa(atoi(*(arv + 1))));
}*/
