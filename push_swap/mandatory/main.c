/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:39:11 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/05 23:39:34 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = creat_stack();
	if (!a && ac)
		return (ft_putendl_fd("Error", 1), 0);
	if (!check_error(av, &a))
		return (ft_putendl_fd("Error", 1), 0);
	b = creat_stack();
	if (a->head && a->qty <= 5 && !is_sorted_as(&a))
		sort_less_5(&a, &b);
	else if (a->head && !is_sorted_as(&a))
		push_swap(&a, &b);
	failure(a);
	failure(b);
	return (0);
}

// void	print(t_stack *s)
// {
// 	int		i;
// 	t_node	*n;

// 	i = 0;
// 	n = s->head;
// 	while (i++ < s->qty)
// 	{
// 		printf("[%d] : %d ----> cost %d\n",i , n->data, n->cost);
// 		n = n->next;
// 	}
// }
