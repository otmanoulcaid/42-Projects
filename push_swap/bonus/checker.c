/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:17:51 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/01/06 00:59:55 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	execute_instruction(char *instruction, t_stack **a, t_stack **b)
{
	if ((*b)->head && (*a)->head && ft_strcmp("rrr\n", instruction) == 0)
		return (r_rotate_both(a, b, NULL), 1);
	else if ((*b)->head && (*a)->head && ft_strcmp("rr\n", instruction) == 0)
		return (rotate_both(a, b, NULL), 1);
	else if ((*a)->head && ft_strcmp("ra\n", instruction) == 0)
		return (rotate(a, NULL), 1);
	else if ((*b)->head && ft_strcmp("rb\n", instruction) == 0)
		return (rotate(b, NULL), 1);
	else if ((*a)->head && ft_strcmp("rra\n", instruction) == 0)
		return (r_rotate(a, NULL), 1);
	else if ((*b)->head && ft_strcmp("rrb\n", instruction) == 0)
		return (r_rotate(b, NULL), 1);
	else if ((*a)->qty > 2 && ft_strcmp("sa\n", instruction) == 0)
		return (swap(&(*a)->head->data, &(*a)->head->next->data, NULL), 1);
	else if ((*b)->qty > 2 && ft_strcmp("sb\n", instruction) == 0)
		return (swap(&(*b)->head->data, &(*b)->head->next->data, NULL), 1);
	else if ((*b)->head && ft_strcmp("pa\n", instruction) == 0)
		return (push_in(a, ft_pop(b), NULL), 1);
	else if ((*a)->head && ft_strcmp("pb\n", instruction) == 0)
		return (push_in(b, ft_pop(a), NULL), 1);
	return (0);
}

void	del(void *p)
{
	free(p);
}

void	get_mouvements(t_list **lst)
{
	int		i;
	char	*buffer;
	t_list	*tmp;

	buffer = (char *)malloc(5);
	if (!buffer)
		return ;
	i = read(0, buffer, 5);
	while (i)
	{
		buffer[i] = '\0';
		tmp = ft_lstnew(ft_strdup(buffer));
		if (!tmp)
			return (free(buffer), ft_lstclear(lst, &del), exit(1));
		ft_lstadd_back(lst, tmp);
		i = read(0, buffer, 5);
	}
}

int	checker(t_stack **a, t_stack **b)
{
	t_list	*list;
	t_list	*tmp;

	list = NULL;
	get_mouvements(&list);
	tmp = list;
	while (list)
	{
		if (!execute_instruction(list->content, a, b))
			return (ft_lstclear(&list, &del), failure(*a), failure(*b),
				ft_putendl_fd("invalid mouvement", 1), exit(1), 0);
		list = list->next;
	}
	if (is_sorted_as(a))
		return (ft_lstclear(&list, &del), 1);
	return (ft_lstclear(&list, &del), 0);
}
