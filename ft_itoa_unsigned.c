/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:25:00 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 07:01:10 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*next(unsigned int n, int len, char *str)
{
	unsigned int nbr;

	nbr = n;
	str[len--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[len] = nbr % 10 + 48;
		nbr = nbr / 10;
		if (nbr == 0)
			return (str);
		len--;
	}
	return (str);
}

int			ft_itoa_unsigned(unsigned int n)
{
	unsigned int	nbr;
	char			*str;
	int				i;

	i = 1;
	nbr = n;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	if (!(str = (char *)malloc((i) + sizeof(char))))
		return (0);
	ft_putstr_string(next(n, i, str));
	return (i);
}
