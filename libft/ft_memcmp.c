/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:56:54 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/10/30 20:48:48 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (*(str1 + i) == *(str2 + i) && i + 1 < n)
		i++;
	return (*(str1 + i) - *(str2 + i));
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n",ft_memcmp("test","tEst",4));
}
*/
