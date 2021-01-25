/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:24:06 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_d(int count, va_list vlist, t_flags *p)
{
	int nbr;

	count = 0;
	nbr = va_arg(vlist, int);
	if (p->width && ((p->precision >= 0) || p->pr == 1))
		return (count += flags_width_precision_d(count, nbr, p));
	else if (p->width && p->zero == 0)
		return (count += flags_width_d(count, nbr, p));
	else if ((p->precision || p->pr == 1 || p->precision == 0) && p->zero == 0)
		return (count += flags_precision_d(count, nbr, p));
	else if (p->width && p->zero)
		return (count += flags_width_zero_d(count, nbr, p));
	else if (p->width == 0 && p->zero)
		return (count += flags_width_zero_d(count, nbr, p));
	return (count);
}
