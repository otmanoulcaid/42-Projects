/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:22:07 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/08 23:20:27 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/minishell.h"

void	unset(t_env **env, char **vars)
{
	t_env	*node;
	t_env	*to_rm;
	int		i;

	node = *env;
	i = -1;
	while (vars[++i])
	{
		while (node)
		{
			if (!ft_strcmp(node->environ, vars[i]))
			{
				to_rm = node;
				if (node->prev)
					node->prev->next = node->next;
				else
					(*env) = (*env)->next;
				(free(to_rm), to_rm = NULL);
				break ;
			}
			node = node->next;
		}
		node = *env;
	}
}

// int	main()
// {
// 	t_env	*test;
// 	t_env	*tmp;
// 	char	*dup;
// 	int		i;

// 	test = NULL;
// 	char prototype[5] = "HOME";
// 	i = 0;
// 	while (i++ < 10)
// 	{
// 		prototype[3]++;
// 		dup = ft_strdup(prototype);
// 		env_add_back(&test, env_new(dup));
// 	}
// 	unset(&test, "HOMF");
// 	tmp = test;
// 	while (tmp)
// 		(puts(tmp->environ), tmp = tmp->next);
// }