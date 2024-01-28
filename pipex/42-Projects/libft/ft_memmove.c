/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:37:52 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/10/30 22:12:18 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (s < d)
	{
		while (len-- > 0)
			*(d + len) = *(s + len);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char t[] = "qwerty";

	printf("%s\n",(char *)ft_memmove(t + 2, t, 3));
	printf("%s\n", (char *)memmove(t + 2, t, 2));
	printf("%s\n",ft_memcpy(t+2, t, 3));
	printf("%c",-63);
	return (0);
}*/
