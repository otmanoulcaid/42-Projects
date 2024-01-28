/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:46:02 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/11 13:17:09 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long l, unsigned int *n)
{
	if (l < 0)
	{
		ft_putchar('-', n);
		ft_putnbr(l * -1, n);
	}
	else if (l > 9)
	{
		ft_putnbr(l / 10, n);
		ft_putchar(l % 10 + 48, n);
	}
	else
		ft_putchar(l + 48, n);
}
