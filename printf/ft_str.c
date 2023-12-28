/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:21:15 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/11 18:19:58 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(va_list args, unsigned int *n)
{
	va_list	cp;

	va_copy(cp, args);
	if (!va_arg(cp, char *))
	{
		ft_putstr("(null)", n);
		va_arg(args, char *);
	}
	else
		ft_putstr(va_arg(args, char *), n);
}
