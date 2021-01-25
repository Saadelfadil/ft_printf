/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:12:30 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/16 15:37:19 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_space(int nbr)
{
	int count;
	int	i;

	count = 0;
	i = 0;
	while (i < nbr)
	{
		count += ft_putchar(' ');
		i++;
	}
	return (count);
}
