/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_nega_posi_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 06:36:47 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	d_positive_my_u(unsigned int nbr, t_flags *p)
{
	int	count;
	int len;

	count = 0;
	len = p->precision;
	if (p->precision < ft_itoa_len_un(nbr))
		len = ft_itoa_len_un(nbr);
	if (p->width > len && p->precision > ft_itoa_len_un(nbr))
		count += ft_putstr_zero(len - ft_itoa_len_un(nbr))
		+ ft_i_u(nbr) + ft_putstr_space(p->width - len);
	else if (p->width && p->precision == 0 && nbr == 0)
		count += ft_putstr_space(p->width);
	else if (p->width && p->precision == -1 && p->pr == 1 && nbr == 0)
		count += ft_putstr_space(p->width);
	else if (p->width > len && p->precision <= ft_itoa_len_un(nbr))
		count += ft_i_u(nbr) + ft_putstr_space(p->width - len);
	else if (p->width <= len && p->precision > ft_itoa_len_un(nbr))
		count += ft_putstr_zero(len - ft_itoa_len_un(nbr)) + ft_i_u(nbr);
	else if (p->width <= len && p->precision <= ft_itoa_len_un(nbr))
		count += ft_i_u(nbr) + ft_putstr_space(p->width - len);
	else if (p->width > len && p->pr)
		count += ft_i_u(nbr) + ft_putstr_space(p->width - len);
	else if (p->width <= len && p->pr)
		count += ft_i_u(nbr);
	return (count);
}

int	d_positive_mn_u(unsigned int nbr, t_flags *p)
{
	int	count;
	int len;

	count = 0;
	len = p->precision;
	if (p->precision < ft_itoa_len_un(nbr))
		len = ft_itoa_len_un(nbr);
	if (p->width > len && p->precision > ft_itoa_len_un(nbr))
		count += ft_putstr_space(p->width - len) +
		ft_putstr_zero(len - ft_itoa_len_un(nbr)) + ft_i_u(nbr);
	else if (p->width && p->precision == 0 && nbr == 0)
		count += ft_putstr_space(p->width);
	else if (p->width && p->precision == -1 && p->pr == 1 && nbr == 0)
		count += ft_putstr_space(p->width);
	else if (p->width > len && p->precision <= ft_itoa_len_un(nbr))
		count += ft_putstr_space(p->width - len) + ft_i_u(nbr);
	else if (p->width <= len && p->precision > ft_itoa_len_un(nbr))
		count += ft_putstr_zero(len - ft_itoa_len_un(nbr)) + ft_i_u(nbr);
	else if (p->width <= len && p->precision <= ft_itoa_len_un(nbr))
		count += ft_putstr_space(p->width - len) + ft_i_u(nbr);
	else if (p->width > len && p->pr)
		count += ft_putstr_space(p->width - len) + ft_i_u(nbr);
	else if (p->width <= len && p->pr)
		count += ft_i_u(nbr);
	return (count);
}
