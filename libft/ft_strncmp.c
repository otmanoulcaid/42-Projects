/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:56:39 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/03 00:12:47 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (*(s1 + i) && *(s1 + i) && *(s1 + i) == *(s2 + i) && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}
/*
int main()
{
	printf("%d\n",strncmp(NULL,NULL , 0));
	printf("%d\n",ft_strncmp(NULL, NULL, 0));
}*/
