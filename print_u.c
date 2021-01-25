/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:06:46 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(int count, va_list vlist, t_flags *p)
{
	unsigned int	nbr;

	count = 0;
	nbr = va_arg(vlist, unsigned int);
	if (p->width == 0 && p->precision < 0 && p->zero == 1)
		return (count += flags_width_zero_u(count, nbr, p));
	else if (nbr == 0 && p->width == 0 && p->precision < 0)
		return (count += flags_width_zero_u(count, nbr, p));
	else if (p->width && ((p->precision >= 0) || p->pr == 1))
		return (count += flags_width_precision_u(count, nbr, p));
	else if (p->width && p->zero == 0)
		return (count += flags_width_u(count, nbr, p));
	else if ((p->precision || p->pr == 1 || p->precision == 0) && p->zero == 0)
		return (count += flags_precision_u(count, nbr, p));
	else if (p->width && p->zero)
		return (count += flags_width_zero_u(count, nbr, p));
	return (count);
}
