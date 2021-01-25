/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_hexa_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:21:28 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/18 18:51:17 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_hexa_len(unsigned long nbr)
{
	char				str[100];
	int					i;
	unsigned long		decimal;

	decimal = 0;
	i = 0;
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
	if (nbr == 0)
		str[i++] = '0';
	str[i] = '\0';
	ft_strrev(str);
	return (i + 2);
}
