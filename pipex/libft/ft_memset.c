/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:31:07 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/03 02:05:55 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;
	unsigned char	cc;
	size_t			i;

	s = (unsigned char *)b;
	cc = (unsigned char)c ;
	i = 0;
	while (i < len)
		*(s + i++) = cc;
	return (b);
}
/*
#include <stdio.h>

int	main()
{
	int i = 1;
	ft_memset(&i, 153, 1);
	ft_memset((char *)&i + 1, 8, 1);
	ft_memset((char *)&i + 2, 0, 1);

	printf("%d\n",i);
}*/
