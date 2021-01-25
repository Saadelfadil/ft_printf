/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:51:18 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags_help1(const char **format,
va_list vlist, t_flags *p, char first)
{
	if (first == '0')
		p->zero = 1;
	if (*format[0] == '-')
		p->minus = 1;
	if (*format[0] == '*')
	{
		p->width = va_arg(vlist, int);
		if (p->width < 0)
		{
			p->width = (p->width) * -1;
			p->minus = 1;
		}
	}
}

void	check_flags_help2(const char **format, va_list vlist, t_flags *p)
{
	int	j;

	j = 1;
	if (*format[0] == '.')
	{
		format[0] += 1;
		if (ft_isdigit(*format[0]) == 1 && j != 0)
		{
			p->precision = atoi(format[0]);
			j = 0;
		}
		else if (*format[0] == '*')
			p->precision = va_arg(vlist, int);
		else
			p->pr = 1;
	}
}
