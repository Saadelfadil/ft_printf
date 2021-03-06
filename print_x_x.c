/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 22:28:32 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_x_x(int count, va_list vlist, t_flags *p)
{
	unsigned long	nbr;
	char			*str;

	count = 0;
	nbr = va_arg(vlist, int);
	str = ft_x_hexa_xx_string(nbr);
	if (p->width && ((p->precision >= 0) || p->pr == 1)
	&& (nbr != 0 || nbr == 0))
		return (count += flags_width_precision_xx(count, str, p));
	else if (p->width && p->zero == 0)
		return (count += flags_width_xx(count, str, p));
	else if ((p->precision || p->pr == 1 || p->precision == 0) && p->zero == 0)
		return (count += flags_precision_xx(count, str, p));
	else if (p->width && p->zero)
		return (count += flags_width_zero_xx(count, str, p));
	else if (p->width == 0 && p->zero == 1 && p->pr == 0 && nbr == 0)
		return (count += ft_putchar(*str));
	else if (p->width == 0 && p->zero == 1 && p->pr == 0 && nbr != 0)
		return (count += ft_putstr(str));
	return (count);
}
