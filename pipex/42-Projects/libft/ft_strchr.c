/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:25:41 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/10/30 20:25:44 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;
	unsigned char	*p;

	p = (unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (*(p + i))
	{
		if (cc == *(p + i))
			return ((char *)p + i);
		i++;
	}
	if (*(p + i) == cc)
		return ((char *)p + i);
	return (NULL);
}
/*
int	main ()
{
	char t[] = "teste";
	printf("%p,%p\n",t,  ft_strchr(t, 357));
}*/
