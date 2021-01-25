/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:48:30 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/20 14:40:42 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_itoa_len(int n)
{
	unsigned int	nbr;
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
	return (i);
}
