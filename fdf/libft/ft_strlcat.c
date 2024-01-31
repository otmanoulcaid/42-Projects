/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:58:04 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/10/30 21:58:06 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	sd;
	size_t	ss;
	size_t	i;
	size_t	j;

	ss = ft_strlen((char *)src);
	if (!dstsize)
		return (ss);
	sd = ft_strlen(dst);
	if (dstsize <= sd)
		return (ss + dstsize);
	i = 0;
	j = sd;
	while (*(src + i) && i < dstsize - sd - 1)
		*(dst + j++) = *(src + i++);
	*(dst + j) = '\0';
	return (sd + ss);
}
/*
#include <stdio.h>
int main ()
{
	char src[3] = "wo";
	char dst[20] = "hello";
	printf("%d", (int)ft_strlcat(dst, src, 5));
}*/
