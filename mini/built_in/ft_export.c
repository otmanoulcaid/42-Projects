/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:39:06 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/08 23:14:11 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*sort_list(t_env *env)
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
			if (ft_strcmp(i->environ, j->environ) > 0)
			{
				help = i->environ;
				i->environ = j->environ;
				j->environ = help;
			}
			j = j->next;
		}
		i = i->next;
	}
	return (env);
}

void	ft_export(t_env **env, char **to_add, int add)
{
	t_env	*node;
	t_env	*tmp;
	int		i;

	if (add)
	{
		while (tmp->next)
			tmp = tmp->next;
		i = -1;
		while (to_add[++i])
		{
			node = env_new(to_add);
			if (!node)
				ft_throw("ERROR_LSTNEW_EXPORT");
			env_add_back(env, node);
		}
		return ;
	}
	tmp = *env;
	print(sort_list(tmp));
}

// int	main(int ac, char **av, char **env)
// {
// 	char *str;
// 	int	i;
// 	i = 0;
// 		*list_env = NULL;
// 		*node;
// 	while (env[i])
// 	{
// 		str = ft_strdup(env[i]);
// 		if (!str)
// 			ft_throw("EXPORT_STRDUP_ERROR");
// 		node = tokennew(str);
// 		if (!node)
// 			ft_throw("hna");
// 		tokenadd_back(&list_env, node);
// 		i++;
// 	}
// 	export(&list_env, NULL, 0);
// 	tokenclear(&list_env);
// }