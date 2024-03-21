/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:33:35 by tamehri           #+#    #+#             */
/*   Updated: 2024/03/21 01:32:11 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	l;

	l = 0;
	if (n <= 0)
		l++;
	while (n)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char	*ft_str(char *s, long n, int l)
{
	if (n == 0)
		*s = '0';
	while (n > 0)
	{
		*(s + l--) = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		l;
	long	nb;

	nb = n;
	l = ft_len(nb);
	res = malloc(sizeof(char) * (l + 1));
	if (!res)
		return (NULL);
	*(res + l) = '\0';
	if (n < 0)
	{
		*res = '-';
		nb *= -1;
	}
	return (ft_str(res, nb, l - 1));
}
