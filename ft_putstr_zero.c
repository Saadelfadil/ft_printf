/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:50:06 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 07:40:08 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_zero(int nbr)
{
	int count;
	int	i;

	count = 0;
	i = 0;
	while (i < nbr)
	{
		count += ft_putchar('0');
		i++;
	}
	return (count);
}
