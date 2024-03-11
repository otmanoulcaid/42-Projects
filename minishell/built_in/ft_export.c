/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:05:03 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/11 15:05:04 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*copy_list(t_env *list)
{
	t_env	*env;
	t_env	*node;
	char	*name;
	char	*value;

	env = NULL;
	while (list)
	{
		name = ft_strdup(list->name);
		value = ft_strdup(list->value);
		if (!name || !value)
			ft_throw("ERROR_DUP_EXPORT", 1);
		node = env_new(name, value);
		if (!node)
			ft_throw("ERROR_NEW_NODE_EXPORT", 1);
		env_add_back(&env, node);
		list = list->next;
	}
	return (env);
}

void	sort_list(t_env *env)
{
	t_env	*i;
	t_env	*j;
	char	*help;

	i = env;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (ft_strcmp(i->name, j->name) > 0)
			{
				help = i->name;
				i->name = j->name;
				j->name = help;
				help = i->value;
				i->value = j->value;
				j->value = help;
			}
			j = j->next;
		}
		i = i->next;
	}
	print(env, 0);
}

void	new_var(t_env *env, char **splited)
{
	t_env	*tmp;
	t_env	*node;

	tmp = env;
	while (tmp->next)
		tmp = tmp->next;
	node = env_new(splited[0], splited[1]);
	if (!node)
		ft_throw("ERROR_LSTNEW_EXPORT", 1);
	env_add_back(&env, node);
}

void	append(t_env *env, char **splited)
{
	t_env	*tmp;
	char	*join;

	tmp = env;
	while (env->next && ft_strncmp(splited[0], env->name,
			ft_strlen(splited[0]) - 1))
		env = env->next;
	puts(env->value);
	join = ft_strjoin(env->value, splited[1]);
	if (!join)
		ft_throw("ERROR_SUBSTR_APPEND<<<", 1);
	(free(env->value), env->value = NULL);
	env->value = join;
	env = tmp;
}

void	ft_export(t_env *env, char **to_add, int add)
{
	char	**splited;
	t_env	*tmp;
	int		i;

	i = -1;
	while (add && to_add[++i])
	{
		splited = ft_split(to_add[i], '=');
		if (!splited)
			ft_throw("ERROR_SPLIT_EXPORT", 1);
		if (splited[0][ft_strlen(splited[0]) - 1] == '+')
			append(env, splited);
		else
			new_var(env, splited);
	}
	if (!add)
	{
		tmp = copy_list(env);
		(sort_list(tmp), env_clear(&tmp));
	}
}
