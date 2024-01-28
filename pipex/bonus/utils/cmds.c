/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:17:36 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/28 01:09:17 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	**get_cmd(char *av, char **env)
{
	char	**bins;
	char	**full_cmd;
	char	*cmd;

	while (!ft_strnstr(*env, "PATH", 4))
		env++;
	bins = ft_split(ft_strchr(*env, '=') + 1, ':');
	if (!bins)
		ft_throw(strerror(errno));
	full_cmd = ft_split(av, ' ');
	if (!full_cmd)
		(failure(bins), ft_throw(strerror(errno)));
	cmd = valid_cmd(*full_cmd, bins);
	if (!cmd)
		(failure(full_cmd), failure(bins), ft_throw(strerror(errno)));
	return (swap(full_cmd, &cmd), free(cmd), cmd = NULL, full_cmd);
}

char	*valid_cmd(char *cmd, char **bins)
{
	char	*str_tmp1;
	char	*str_tmp2;
	int		i;

	i = 0;
	while (bins[i])
	{
		str_tmp1 = ft_strjoin(bins[i++], "/");
		if (!str_tmp1)
			ft_throw(strerror(errno));
		str_tmp2 = ft_strjoin(str_tmp1, cmd);
		if (!str_tmp2)
			(free(str_tmp1), ft_throw(strerror(errno)));
		free(str_tmp1);
		if (!access(str_tmp2, F_OK) && !access(str_tmp2, X_OK))
			return (str_tmp2);
		free(str_tmp2);
		str_tmp2 = NULL;
		str_tmp1 = NULL;
	}
	return (NULL);
}
