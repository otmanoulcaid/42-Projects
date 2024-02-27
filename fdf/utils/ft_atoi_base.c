/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:39:30 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/27 20:39:48 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi_base(char *str)
{
	int	nbr;

	nbr = 0;
	while (*str)
	{
		if (is_upper(*str))
			nbr += (nbr * 16 + ((*str - 65) + 10));
		else if (is_lower(*str))
			nbr += (nbr * 16 + ((*str - 97) + 10));
		else
			nbr += (nbr * 16 + ((*str - 48) + 10));
		str++;
	}
	return (nbr);
}