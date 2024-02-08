/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:25:41 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/02 01:47:26 by ooulcaid         ###   ########.fr       */
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
