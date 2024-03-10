/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:10:05 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/10 14:02:16 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(char *path)
{
	struct stat	st;

	if (stat(path, &st) < 0)
		ft_throw("NO_SUCH_FILE_OR_DIRECTORY");
	if (!S_ISDIR(st.st_mode))
		ft_throw("IS_NOT_A_DIRECTORY");
	if (!path)
	{
		if (chdir("/Users/ooulcaid") < 0)
			ft_throw(strerror(errno));
	}
	else if (chdir(path) < 0)
		ft_throw(strerror(errno));
	printf("%d\n", st.st_mode);
	ft_putstr_fd(getcwd(NULL, 0), 1);
}
// int main(int ac, char **av)
// {
// 	ft_cd(av[1], ac);
// }