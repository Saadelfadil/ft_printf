/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_nega_posi_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 05:23:58 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	d_negative_my_x(char *nbr, t_flags *p)
{
	int	count;
	int len;

	count = 0;
	len = p->precision;
	if (p->precision < ft_strlen(nbr))
		len = ft_strlen(nbr);
	if (p->width > len && p->precision > ft_strlen(nbr))
		count += ft_putchar('-') + ft_putstr_zero(len - ft_strlen(nbr)) +
		ft_putstr(nbr) + ft_putstr_space(p->width - len - 1);
	else if (p->width > len && p->precision <= ft_strlen(nbr))
		count += ft_putchar('-') + ft_putstr(nbr) +
		ft_putstr_space(p->width - len - 1);
	else if (p->width <= len && p->precision > ft_strlen(nbr))
		count += ft_putchar('-') + ft_putstr_zero(len - ft_strlen(nbr)) +
		ft_putstr(nbr);
	else if (p->width <= len && p->precision <= ft_strlen(nbr))
		count += ft_putchar('-') + ft_putstr(nbr);
	else if (p->width > len && p->pr)
		count += ft_putchar('-') + ft_putstr(nbr) +
		ft_putstr_space(p->width - len - 1);
	else if (p->width <= len && p->pr)
		count += ft_putchar('-') + ft_putstr(nbr);
	return (count);
}

int	d_negative_mn_x(char *nbr, t_flags *p)
{
	int	count;
	int len;

	count = 0;
	len = p->precision;
	if (p->precision < ft_strlen(nbr))
		len = ft_strlen(nbr);
	if (p->width > len && p->precision > ft_strlen(nbr))
		count += ft_putstr_space(p->width - len - 1) + ft_putchar('-') +
		ft_putstr_zero(len - ft_strlen(nbr)) + ft_putstr(nbr);
	else if (p->width > len && p->precision <= ft_strlen(nbr))
		count += ft_putstr_space(p->width - len - 1) +
		ft_putchar('-') + ft_putstr(nbr);
	else if (p->width <= len && p->precision > ft_strlen(nbr))
		count += ft_putchar('-') + ft_putstr_zero(len - ft_strlen(nbr)) +
		ft_putstr(nbr);
	else if (p->width <= len && p->precision <= ft_strlen(nbr))
		count += ft_putchar('-') + ft_putstr(nbr);
	else if (p->width > len && p->pr)
		count += ft_putstr_space(p->width - len - 1) +
		ft_putchar('-') + ft_putstr(nbr);
	else if (p->width <= len && p->pr)
		count += ft_putchar('-') + ft_putstr(nbr);
	return (count);
}

int	d_positive_my_x(char *nbr, t_flags *p)
{
	int	count;
	int len;

	count = 0;
	len = p->precision;
	if (p->precision < ft_strlen(nbr))
		len = ft_strlen(nbr);
	if (p->width > len && p->precision > ft_strlen(nbr))
		count += ft_putstr_zero(len - ft_strlen(nbr)) + ft_putstr(nbr) +
		ft_putstr_space(p->width - len);
	else if (p->width && p->precision == 0 && *nbr == 48)
		count += ft_putstr_space(p->width);
	else if (p->width && p->precision == -1 && p->pr == 1 && *nbr == 48)
		count += ft_putstr_space(p->width);
	else if (p->width > len && p->precision <= ft_strlen(nbr))
		count += ft_putstr(nbr) + ft_putstr_space(p->width - len);
	else if (p->width <= len && p->precision > ft_strlen(nbr))
		count += ft_putstr_zero(len - ft_strlen(nbr)) + ft_putstr(nbr);
	else if (p->width <= len && p->precision <= ft_strlen(nbr))
		count += ft_putstr(nbr) + ft_putstr_space(p->width - len);
	else if (p->width > len && p->pr)
		count += ft_putstr(nbr) + ft_putstr_space(p->width - len);
	else if (p->width <= len && p->pr)
		count += ft_putstr(nbr);
	return (count);
}

int	d_positive_mn_x(char *nbr, t_flags *p)
{
	int	count;
	int len;

	count = 0;
	len = p->precision;
	if (p->precision < ft_strlen(nbr))
		len = ft_strlen(nbr);
	if (p->width > len && p->precision > ft_strlen(nbr))
		count += ft_putstr_space(p->width - len) +
		ft_putstr_zero(len - ft_strlen(nbr)) + ft_putstr(nbr);
	else if (p->width && p->precision == 0 && *nbr == 48)
		count += ft_putstr_space(p->width);
	else if (p->width && p->precision == -1 && p->pr == 1 && *nbr == 48)
		count += ft_putstr_space(p->width);
	else if (p->width > len && p->precision <= ft_strlen(nbr) && *nbr != 48)
		count += ft_putstr_space(p->width - len) + ft_putstr(nbr);
	else if (p->width <= len && p->precision > ft_strlen(nbr))
		count += ft_putstr_zero(len - ft_strlen(nbr)) + ft_putstr(nbr);
	else if (p->width <= len && p->precision <= ft_strlen(nbr))
		count += ft_putstr_space(p->width - len) + ft_putstr(nbr);
	else if (p->width > len && p->pr && *nbr != 48)
		count += ft_putstr_space(p->width - len) + ft_putstr(nbr);
	else if (p->width <= len && p->pr)
		count += ft_putstr(nbr);
	return (count);
}
