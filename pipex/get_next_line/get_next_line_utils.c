/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:29:17 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/01 22:43:09 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

int	get_index(char *s)
{
	int	l;

	l = 0;
	while (*(s + l) && *(s + l) != '\n')
		l++;
	return (l);
}

int	exist(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_cpy(char *dst, char *src, unsigned int len)
{
	unsigned int	i;

	if (!dst || !src || !len)
		return ;
	i = 0;
	while (i < len)
	{
		*(dst + i) = *(src + i);
		i++;
	}
}
