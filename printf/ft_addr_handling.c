/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:31:39 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/11 13:20:02 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addr_handling(void *p, unsigned int *n)
{
	unsigned long	l;

	l = (unsigned long)p;
	if (l == LONG_MAX)
		ft_putstr("0x7fffffffffffffff", n);
	else if ((long)l == LONG_MIN)
		ft_putstr("0x8000000000000000", n);
	else if (l == ULONG_MAX)
		ft_putstr("0xffffffffffffffff", n);
	else if (l == -ULONG_MAX)
		ft_putstr("0x1", n);
	else
	{
		ft_putstr("0x", n);
		hexa_handling(l, "0123456789abcdef", n);
	}
}
