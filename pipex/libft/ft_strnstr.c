/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:06:42 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/27 17:07:42 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	int	i;
	int	j;

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
