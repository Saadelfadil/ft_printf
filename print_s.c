/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:28:04 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(int count, va_list vlist, t_flags *p)
{
	char	*str;

	count = 0;
	str = va_arg(vlist, char *);
	if (p->width && (p->precision >= 0))
		return (count += flags_width_precision(count, str, p));
	if (p->width)
		return (count += flags_width(count, str, p));
	if (p->precision)
		return (count += flags_precision(count, str, p));
	return (count);
}
