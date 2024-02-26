/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:09:02 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/26 16:23:19 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		l = (*lst)->next;
		del((*lst)->data);
		free(*lst);
		*lst = l;
	}
	*lst = NULL;
}
