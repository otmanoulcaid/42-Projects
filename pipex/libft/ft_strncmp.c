/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:56:39 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/02 00:43:10 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	if (!n)
		return (0);
	i = 0;
	while (*(s1 + i) && *(s1 + i) && *(s1 + i) == *(s2 + i) && i < n)
		i++;
	if (i == n)
		return (0);
	return (*(s1 + i) - *(s2 + i));
}
