/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_all_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:40:36 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flags_width_precision_x(int count, char *nbr, t_flags *p)
{
	count = 0;
	if (p->width && (p->precision >= 0 || p->pr))
	{
		if (p->minus)
		{
			if (nbr < 0)
				count += d_negative_my_x(nbr, p);
			else
				count += d_positive_my_x(nbr, p);
		}
		else
		{
			if (nbr < 0)
				count += d_negative_mn_x(nbr, p);
			else
				count += d_positive_mn_x(nbr, p);
		}
	}
	return (count);
}

int		flags_width_x(int count, char *nbr, t_flags *p)
{
	count = 0;
	if (p->width != 0 && p->pr == 0 && p->precision != 0)
	{
		if (p->minus != 0)
		{
			if (p->width > ft_strlen(nbr))
				count = (ft_putstr(nbr) +
				ft_putstr_space((p->width) - ft_strlen(nbr)));
			else
				count = (ft_putstr_space((p->width)
				- ft_strlen(nbr)) + ft_putstr(nbr));
		}
		else
		{
			if (p->width > ft_strlen(nbr))
				count = (ft_putstr_space((p->width)
				- ft_strlen(nbr)) + ft_putstr(nbr));
			else
				count = (ft_putstr(nbr) +
				ft_putstr_space((p->width) - ft_strlen(nbr)));
		}
	}
	else
		count = (ft_putstr_space((p->width)));
	return (count);
}

int		flags_precision_x(int count, char *nbr, t_flags *p)
{
	count = 0;
	if (p->precision < 0 && p->pr != 1)
		return (count = ft_putstr(nbr));
	if (p->precision >= 0 && p->width == 0)
	{
		if (p->precision > 0)
		{
			if (p->precision > ft_strlen(nbr))
				count += (ft_putstr_zero((p->precision)
				- ft_strlen(nbr)) + ft_putstr(nbr));
			else if (p->precision <= ft_strlen(nbr))
				count += (ft_putstr(nbr) +
				ft_putstr_zero((p->precision) - ft_strlen(nbr)));
		}
		else if (p->width == 0 && *nbr != 48
		&& (p->pr == 1 || p->precision == 0))
			count += ft_putstr(nbr);
	}
	else if (p->width == 0 && *nbr != 48 && p->pr == 1)
		count += ft_putstr(nbr);
	else if (p->width == 0 && p->minus == 0 &&
	p->precision == -1 && p->pr == 0)
		count += ft_putstr(nbr);
	return (count);
}

int		flags_width_zero_x(int count, char *nbr, t_flags *p)
{
	count = 0;
	if (p->width != 0 && p->pr == 0
	&& p->precision != 0 && p->zero == 1)
	{
		if (p->width > ft_strlen(nbr))
			count += (ft_putstr_zero((p->width)
			- (ft_strlen(nbr) + count)) + ft_putstr(nbr));
		else
			count += (ft_putstr(nbr)
			+ ft_putstr_zero((p->width) - (ft_strlen(nbr) + count)));
	}
	else
		count = (ft_putstr_space((p->width)));
	return (count);
}
