/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:18:58 by tamehri           #+#    #+#             */
/*   Updated: 2024/03/21 00:40:19 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) && *(s2 + i) && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}
