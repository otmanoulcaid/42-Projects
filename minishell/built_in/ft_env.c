/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:26:43 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/19 17:27:31 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_shell *data, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->name)
			printf("%s", tmp->name);
		if (tmp->value)
			printf("=%s", tmp->value);
		printf("\n");
		tmp = tmp->next;
	}
	data->status = 0;
	if (data->cmd_nbr > 1)
		exit(0);
}
