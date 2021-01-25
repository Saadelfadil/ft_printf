/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_hexa_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:51:24 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_str(unsigned long nbr)
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

char			*ft_x_hexa_p(unsigned long nbr, t_flags *p)
{
	char				*str;
	int					i;
	unsigned long		decimal;
	unsigned long		tmp;

	decimal = 0;
	i = 0;
	str = malloc(sizeof(unsigned long) * len_str(nbr));
	tmp = nbr;
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
	if (tmp == 0 && p->pr == 0)
		str[i++] = '0';
	str[i] = '\0';
	ft_strrev(str);
	str = ft_strjoin("0x", str);
	return (str);
}
