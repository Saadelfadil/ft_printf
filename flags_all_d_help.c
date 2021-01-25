/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_all_d_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 04:50:15 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_all_d_help1(int count, long nbr, int n_nbr, t_flags *p)
{
	if (nbr < 0)
	{
		n_nbr = ft_itoa_len(nbr) - 1;
		nbr = nbr * -1;
		count += ft_putchar('-');
	}
	if (p->precision > n_nbr)
		count += (ft_putstr_zero((p->precision) - n_nbr) + ft_itoa(nbr));
	else if (p->precision <= n_nbr)
		count += (ft_itoa(nbr) + ft_putstr_zero((p->precision) - n_nbr));
	return (count);
}

int	flags_all_d_help2(int count, long nbr, int n_nbr, t_flags *p)
{
	if (nbr < 0)
	{
		n_nbr = ft_itoa_len(nbr) - 1;
		nbr = nbr * -1;
		if (p->width >= ft_itoa_len(nbr))
			return (count = (ft_putstr_zero((p->width) - (ft_itoa_len(nbr) +
			ft_putchar('-'))) + ft_itoa(nbr) + 1));
		else
			return (count = ((ft_putchar('-') + ft_itoa(nbr)) +
			ft_putstr_zero((p->width) - (ft_itoa_len(nbr)))));
	}
	if (p->width > ft_itoa_len(nbr))
		count += ft_putstr_zero((p->width) - (ft_itoa_len(nbr))) + ft_itoa(nbr);
	else
		count += ft_itoa(nbr) + ft_putstr_zero((p->width) - (ft_itoa_len(nbr)));
	return (count);
}
