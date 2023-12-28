/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:09:23 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/03 00:32:44 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*t;
	unsigned int	l;
	size_t			buff;

	if (!s)
		return (NULL);
	l = (unsigned int)ft_strlen((char *)s);
	i = 0;
	if (start >= l)
		return (ft_strdup(""));
	if (len > l - start)
		buff = l - start;
	else 
		buff = len;
	t = (char *)malloc((buff + 1) * sizeof(char));
	if (!t)
		return (NULL);
	while (i < len && *(s + start + i))
	{
		*(t + i) = *(s + start + i);
		i++;
	}
	*(t + i) = '\0';
	return (t);
}
/*
#include <stdio.h>

int main ()
{
	printf("%s\n", ft_substr("hola", 0, 18446744073709551615));
}*/
