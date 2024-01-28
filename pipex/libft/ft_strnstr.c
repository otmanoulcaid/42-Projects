/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:06:42 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/03 00:19:15 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	else if (!haystack && !len)
		return (NULL);
	i = 0;
	while (*(haystack + i) && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && i + j < len)
			j++;
		if (!*(needle + j))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	printf("me->:%s:\n", ft_strnstr(NULL,"" ,1));
}*/
