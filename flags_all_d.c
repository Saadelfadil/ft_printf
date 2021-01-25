/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_all_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:22:49 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flags_width_precision_d(int count, long nbr, t_flags *p)
{
	count = 0;
	if (p->width && (p->precision >= 0 || p->pr))
	{
		if (p->minus)
		{
			if (nbr < 0)
				count += d_negative_my(nbr, p);
			else
				count += d_positive_my(nbr, p);
		}
		else
		{
			if (nbr < 0)
				count += d_negative_mn(nbr, p);
			else
				count += d_positive_mn(nbr, p);
		}
	}
	return (count);
}

int		flags_width_d(int count, int nbr, t_flags *p)
{
	count = 0;
	if (p->width != 0 && p->pr == 0 && p->precision != 0)
		if (p->minus != 0)
			if (p->width > ft_itoa_len(nbr))
				count = (ft_itoa(nbr) + ft_putstr_space((p->width)
				- ft_itoa_len(nbr)));
			else
				count = (ft_putstr_space((p->width)
				- ft_itoa_len(nbr)) + ft_itoa(nbr));
		else
		{
			if (p->width > ft_itoa_len(nbr))
				count = (ft_putstr_space((p->width)
				- ft_itoa_len(nbr)) + ft_itoa(nbr));
			else
				count = (ft_itoa(nbr) + ft_putstr_space((p->width)
				- ft_itoa_len(nbr)));
		}
	else
		count = (ft_putstr_space((p->width)));
	return (count);
}

int		flags_precision_d(int count, long nbr, t_flags *p)
{
	int n_nbr;

	count = 0;
	n_nbr = ft_itoa_len(nbr);
	if (p->precision >= 0 && p->width == 0)
	{
		if (p->precision > 0)
			count += flags_all_d_help1(count, nbr, n_nbr, p);
		else if (p->width == 0 && nbr != 0
		&& (p->pr == 1 || p->precision == 0))
			count += ft_itoa(nbr);
	}
	else if (p->width == 0 && nbr != 0 && p->pr == 1)
		count += ft_itoa(nbr);
	else if (p->width == 0 && p->minus == 0
	&& p->precision < 0 && p->pr == 0)
		count += ft_itoa(nbr);
	else if (p->width == 0 && p->minus != 0
	&& p->precision == -1 && p->pr == 0)
		count += ft_itoa(nbr);
	return (count);
}

int		flags_width_zero_d(int count, long nbr, t_flags *p)
{
	int n_nbr;

	count = 0;
	n_nbr = ft_itoa_len(nbr);
	if (p->width != 0 && p->pr == 0
	&& p->precision != 0 && p->zero == 1)
		count += flags_all_d_help2(count, nbr, n_nbr, p);
	else if (p->width == 0 && p->pr == 0
	&& p->precision != 0 && p->zero == 1)
		count += ft_itoa(nbr);
	else
		count = (ft_putstr_space((p->width)));
	return (count);
}
