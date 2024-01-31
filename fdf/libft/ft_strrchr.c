/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:25:26 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/31 15:56:20 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;

	if (!s)
		return (NULL);
	cc = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (cc == *(s + i))
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
