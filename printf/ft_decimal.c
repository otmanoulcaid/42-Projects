/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:22:10 by ooulcaid          #+#    #+#             */
/*   Updated: 2023/11/11 13:16:51 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_decimal(va_list args, const char *s, unsigned int *n)
{
	if (*s && (*(s + 1) == 'd' || *(s + 1) == 'i'))
		ft_putnbr(va_arg(args, int), n);
	else if (*s && *(s + 1) == 'u')
		ft_putnbr(va_arg(args, unsigned int), n);
}
