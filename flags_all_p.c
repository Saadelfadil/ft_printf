/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_all_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:59:59 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flags_width_p(int count, char *nbr, t_flags *p)
{
	count = 0;
	if (p->width != 0)
	{
		if (p->minus != 0)
		{
			if (p->width > (ft_strlen(nbr)))
				count = (ft_putstr(nbr) + ft_putstr_space((p->width)
				- (ft_strlen(nbr))));
			else
				count = ft_putstr(nbr);
		}
		else
		{
			if (p->width > (ft_strlen(nbr)))
				count = (ft_putstr_space((p->width)
				- (ft_strlen(nbr))) + ft_putstr(nbr));
			else
				count = ft_putstr(nbr);
		}
	}
	else
		count = ft_putstr(nbr);
	return (count);
}

int		flags_width_p2(int count, char *nbr, t_flags *p)
{
	int len;

	len = ft_strlen(nbr);
	if (p->width != 0)
	{
		if (p->pr == 1)
			len = ft_strlen(nbr);
		if (p->minus != 0)
		{
			if (p->width > (len))
				count = (ft_putstr(nbr) + ft_putstr_space((p->width) - (len)));
			else
				count = ft_putstr(nbr);
		}
		else
		{
			if (p->width > (len))
				count = (ft_putstr_space((p->width) - (len)) + ft_putstr(nbr));
			else
				count = ft_putstr(nbr);
		}
	}
	else
		count = ft_putstr(nbr);
	return (count);
}
