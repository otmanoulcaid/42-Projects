/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:39:48 by tamehri           #+#    #+#             */
/*   Updated: 2024/03/08 17:04:03 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_throw(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	throw_error(char *str)
{
	ft_putendl_fd(str, 2);
	return (1);
}

void	free_2d(char **strings)
{
	int	i;

	i = -1;
	while (strings[++i])
		free(strings[i]);
	free(strings);
}