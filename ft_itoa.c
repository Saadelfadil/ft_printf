/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:53:56 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 07:40:19 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*next(int n, int len, char *str)
{
	unsigned int nbr;

	if (n < 0)
	{
		n *= -1;
	}
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

int				ft_itoa(long n)
{
	unsigned long	nbr;
	char			*str;
	int				i;
	int				v;

	v = 0;
	i = 1;
	if (n < 0)
	{
		n *= -1;
		v = 1;
		i++;
	}
	nbr = n;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	if (!(str = (char *)malloc((i) + sizeof(char))))
		return (0);
	if (v == 1)
		str[0] = '-';
	ft_putstr_string(next(n, i, str));
	return (i);
}
