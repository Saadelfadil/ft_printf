/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_hexa_xx_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 23:14:28 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 14:38:34 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_str(unsigned int nbr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char			*ft_x_hexa_xx_string(unsigned int nbr)
{
	char				*str;
	int					i;
	unsigned int		decimal;
	int					count;

	decimal = 0;
	count = 0;
	i = 0;
	str = malloc(sizeof(unsigned int) * len_str(nbr));
	if (nbr == 0)
		str[i++] = '0';
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
	return (str);
}
