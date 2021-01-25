/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:32:59 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(int count, va_list vlist, t_flags *p)
{
	unsigned long	nbr;
	char			*str;

	count = 0;
	nbr = va_arg(vlist, unsigned long);
	str = ft_x_hexa_p(nbr, p);
	if ((p->width || p->width == 0) && p->pr == 0)
		count += flags_width_p(count, str, p);
	else if (p->pr == 1 && nbr == 0 && p->width == 0)
		count += ft_putstr("0x");
	else if (p->pr == 1)
		count += flags_width_p2(count, str, p);
	return (count);
}
