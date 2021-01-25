/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 20:18:03 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/09 20:49:32 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int			i;
	long		ope;
	long		resu;

	i = 0;
	while ((str[i] > 0 && str[i] < 27) || (str[i] > 27 && str[i] <= 32))
		i++;
	ope = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ope = -1;
		i++;
	}
	resu = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (resu < 0 && ope < 0)
			return (0);
		if (resu < 0 && ope > 0)
			return (-1);
		resu = resu * 10 + (str[i] - '0');
		i++;
	}
	return (resu * ope);
}
