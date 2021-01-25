/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_xhexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 22:24:37 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/11 19:01:47 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_xhexa(unsigned int nbr)
{
	char				str[20];
	int					i;
	unsigned int		decimal;
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
			str[i] = 55 + decimal;
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
