/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:20:13 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/27 12:47:37 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	failure(char **str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (*(str + i))
			free(*(str + i++));
		free(str);
	}
}

void	ft_throw(char *strerr)
{
	ft_putendl_fd(strerr, 2);
	exit(EXIT_FAILURE);
}
