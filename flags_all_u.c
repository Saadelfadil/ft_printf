/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_all_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:02:51 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_width_precision_u(int count, unsigned int nbr, t_flags *p)
{
	count = 0;
	if (p->width && (p->precision >= 0 || p->pr))
	{
		if (p->minus)
			count += d_positive_my_u(nbr, p);
		else
			count += d_positive_mn_u(nbr, p);
	}
	return (count);
}

int	flags_width_u(int count, unsigned int nbr, t_flags *p)
{
	count = 0;
	if (p->width != 0 && p->pr == 0 && p->precision != 0)
	{
		if (p->minus != 0)
		{
			if (p->width > ft_itoa_len_un(nbr))
				count = (ft_itoa_unsigned(nbr) + ft_putstr_space((p->width)
				- ft_itoa_len_un(nbr)));
			else
				count = (ft_putstr_space((p->width) - ft_itoa_len_un(nbr))
				+ ft_itoa_unsigned(nbr));
		}
		else
		{
			if (p->width > ft_itoa_len_un(nbr))
				count = (ft_putstr_space((p->width) - ft_itoa_len_un(nbr))
				+ ft_itoa_unsigned(nbr));
			else
				count = (ft_itoa_unsigned(nbr) + ft_putstr_space((p->width)
				- ft_itoa_len_un(nbr)));
		}
	}
	else
		count = (ft_putstr_space((p->width)));
	return (count);
}

int	flags_precision_u(int count, unsigned int nbr, t_flags *p)
{
	count = 0;
	if (p->precision >= 0 && p->width == 0)
	{
		if (p->precision > 0)
		{
			if (p->precision > ft_itoa_len_un(nbr))
				count += (ft_putstr_zero((p->precision)
				- ft_itoa_len_un(nbr)) + ft_itoa_unsigned(nbr));
			else if (p->precision <= ft_itoa_len_un(nbr))
				count += (ft_itoa_unsigned(nbr) +
				ft_putstr_zero((p->precision) - ft_itoa_len_un(nbr)));
		}
		else if (p->width == 0 && nbr != 0
		&& (p->pr == 1 || p->precision == 0))
			count += ft_itoa_unsigned(nbr);
	}
	else if (p->width == 0 && nbr != 0 && p->pr == 1)
		count += ft_itoa_unsigned(nbr);
	else if (p->width == 0 && p->minus == 0
	&& p->precision < 0 && p->pr == 0)
		count += ft_itoa_unsigned(nbr);
	else if (p->width == 0 && p->minus != 0
	&& p->precision == -1 && p->pr == 0)
		count += ft_itoa_unsigned(nbr);
	return (count);
}

int	flags_width_zero_u(int count, unsigned int nbr, t_flags *p)
{
	count = 0;
	if (p->width != 0 && p->pr == 0 && p->precision != 0 && p->zero == 1)
	{
		if (p->width > ft_itoa_len_un(nbr))
			count += (ft_putstr_zero((p->width) -
			(ft_itoa_len_un(nbr) + count)) + ft_itoa_unsigned(nbr));
		else
			count += (ft_itoa_unsigned(nbr)
			+ ft_putstr_zero((p->width) - (ft_itoa_len_un(nbr) + count)));
	}
	else if (p->width == 0 && p->pr == 0 && p->precision != 0
	&& (p->zero == 0 || p->zero != 0) && nbr == 0)
		count += ft_itoa_unsigned(nbr);
	else if (p->width == 0 && p->pr == 0
	&& p->precision < 0 && p->zero == 1)
		count += ft_itoa_unsigned(nbr);
	else
		count = (ft_putstr_space((p->width)));
	return (count);
}
