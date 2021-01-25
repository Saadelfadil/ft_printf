/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_nega_posi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 01:24:53 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	d_negative_my(long nbr, t_flags *p)
{
	int	count;
	int len;

	count = 0;
	nbr *= -1;
	len = p->precision;
	if (p->precision < ft_len(nbr))
		len = ft_len(nbr);
	if (p->width > len && p->precision > ft_len(nbr))
		count += ft_putchar('-') + ft_putstr_zero(len - ft_len(nbr)) +
		ft_itoa(nbr) + ft_putstr_space(p->width - len - 1);
	else if (p->width > len && p->precision <= ft_len(nbr))
		count += ft_putchar('-') + ft_itoa(nbr) +
		ft_putstr_space(p->width - len - 1);
	else if (p->width <= len && p->precision > ft_len(nbr))
		count += ft_putchar('-') + ft_putstr_zero(len - ft_len(nbr)) +
		ft_itoa(nbr);
	else if (p->width <= len && p->precision <= ft_len(nbr))
		count += ft_putchar('-') + ft_itoa(nbr);
	else if (p->width > len && p->pr)
		count += ft_putchar('-') + ft_itoa(nbr) +
		ft_putstr_space(p->width - len - 1);
	else if (p->width <= len && p->pr)
		count += ft_putchar('-') + ft_itoa(nbr);
	return (count);
}

int	d_negative_mn(long nbr, t_flags *p)
{
	int	count;
	int len;

	count = 0;
	nbr *= -1;
	len = p->precision;
	if (p->precision < ft_len(nbr))
		len = ft_len(nbr);
	if (p->width > len && p->precision > ft_len(nbr))
		count += ft_putstr_space(p->width - len - 1) + ft_putchar('-') +
		ft_putstr_zero(len - ft_len(nbr)) + ft_itoa(nbr);
	else if (p->width > len && p->precision <= ft_len(nbr))
		count += ft_putstr_space(p->width - len - 1) +
		ft_putchar('-') + ft_itoa(nbr);
	else if (p->width <= len && p->precision > ft_len(nbr))
		count += ft_putchar('-') + ft_putstr_zero(len - ft_len(nbr)) +
		ft_itoa(nbr);
	else if (p->width <= len && p->precision <= ft_len(nbr))
		count += ft_putchar('-') + ft_itoa(nbr);
	else if (p->width > len && p->pr)
		count += ft_putstr_space(p->width - len - 1) +
		ft_putchar('-') + ft_itoa(nbr);
	else if (p->width <= len && p->pr)
		count += ft_putchar('-') + ft_itoa(nbr);
	return (count);
}

int	d_positive_my(long nbr, t_flags *p)
{
	int	count;
	int len;

	count = 0;
	len = p->precision;
	if (p->precision < ft_len(nbr))
		len = ft_len(nbr);
	if (p->width > len && p->precision > ft_len(nbr))
		count += ft_putstr_zero(len - ft_len(nbr)) + ft_itoa(nbr) +
		ft_putstr_space(p->width - len);
	else if (p->width && p->precision == 0 && nbr == 0)
		count += ft_putstr_space(p->width);
	else if (p->width && p->precision == -1 && p->pr == 1 && nbr == 0)
		count += ft_putstr_space(p->width);
	else if (p->width > len && p->precision <= ft_len(nbr))
		count += ft_itoa(nbr) + ft_putstr_space(p->width - len);
	else if (p->width <= len && p->precision > ft_len(nbr))
		count += ft_putstr_zero(len - ft_len(nbr)) + ft_itoa(nbr);
	else if (p->width <= len && p->precision <= ft_len(nbr))
		count += ft_itoa(nbr) + ft_putstr_space(p->width - len);
	else if (p->width > len && p->pr)
		count += ft_itoa(nbr) + ft_putstr_space(p->width - len);
	else if (p->width <= len && p->pr)
		count += ft_itoa(nbr);
	return (count);
}

int	d_positive_mn(long nbr, t_flags *p)
{
	int	count;
	int len;

	count = 0;
	len = p->precision;
	if (p->precision < ft_len(nbr))
		len = ft_len(nbr);
	if (p->width > len && p->precision > ft_len(nbr))
		count += ft_putstr_space(p->width - len) +
		ft_putstr_zero(len - ft_len(nbr)) + ft_itoa(nbr);
	else if (p->width && p->precision == 0 && nbr == 0)
		count += ft_putstr_space(p->width);
	else if (p->width && p->precision == -1 && p->pr == 1 && nbr == 0)
		count += ft_putstr_space(p->width);
	else if (p->width > len && p->precision <= ft_len(nbr))
		count += ft_putstr_space(p->width - len) + ft_itoa(nbr);
	else if (p->width <= len && p->precision > ft_len(nbr))
		count += ft_putstr_zero(len - ft_len(nbr)) + ft_itoa(nbr);
	else if (p->width <= len && p->precision <= ft_len(nbr))
		count += ft_putstr_space(p->width - len) + ft_itoa(nbr);
	else if (p->width > len && p->pr)
		count += ft_putstr_space(p->width - len) + ft_itoa(nbr);
	else if (p->width <= len && p->pr)
		count += ft_itoa(nbr);
	return (count);
}
