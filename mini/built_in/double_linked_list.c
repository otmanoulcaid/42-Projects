/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:45:10 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/09 11:19:10 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	print(t_env **env)
// {
// 	t_env	*tmp;

// 	tmp = *env;
// 	while (tmp)
// 	{
// 		ft_putendl_fd(tmp->environ, 1);
// 		tmp = tmp->next;
// 	}
// }

t_env	*env_new(char *name, char *value)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->name = name;
	env->value = value;
	env->next = NULL;
	env->prev = NULL;
	return (env);
}

void	env_add_back(t_env **linked, t_env *node)
{
	t_env	*tmp;

	if (!linked || !node)
		return ;
	if (!*linked)
		*linked = node;
	else
	{
		tmp = *linked;
		while (tmp->next)
			tmp = tmp->next;
		node->prev = tmp;
		tmp->next = node;
	}
}

// void	env_add_front(t_env **linked, t_env *node)
// {
// 	t_env	*tmp;

// 	if (!linked || !node)
// 		return ;
// 	if (!*linked)
// 		*linked = node;
// 	else
// 	{
// 		tmp = *linked;
// 		node->next = tmp;
// 		tmp->prev = node;
// 		*linked = node;
// 	}
// }

void	env_clear(t_env **env)
{
	t_env	*tmp;

	tmp = (*env);
	while (tmp)
	{
		*env = (*env)->next;
		(free(tmp->name), free(tmp->value), free(tmp));
		tmp = *env;
	}
}
