/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:39:11 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/05 22:11:06 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	a = creat_stack();
	b = creat_stack();
	if (!a || !b)
		exit(1);
	if (!check_error(av, &a))
		return (ft_putendl_fd("Error", 1), 0);
	if (checker(&a, &b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	failure(a);
	failure(b);
	return (0);
}
