/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:07:15 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/26 14:07:15 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
