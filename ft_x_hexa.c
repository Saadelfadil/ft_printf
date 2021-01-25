/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:51:24 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/11 19:01:05 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_hexa(unsigned long nbr)
{
	char				str[100];
	int					i;
	unsigned long		decimal;
	int					count;

	decimal = 0;
	count = 0;
	i = 0;
	if (nbr == 0)
		count += ft_putstr("0");
	while (nbr != 0)
	{
		decimal = nbr % 16;
		if (decimal > 9)
			str[i] = 87 + decimal;
		else
			str[i] = 48 + decimal;
		nbr = nbr / 16;
		i++;
	}
	str[i] = '\0';
	ft_strrev(str);
	count += ft_putstr(str);
	return (count);
}
