/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_all_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:54:53 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_width_precision(int count, char *str, t_flags *p)
{
	count = 0;
	if (p->width != 0 && (p->precision >= 0))
	{
		count += flags_all_s_help1(count, &str, p);
		if (p->precision == 0)
			count = (ft_putstr_space((p->width)));
	}
	else if (p->width != 0 && p->precision == -1)
		count = (ft_putstr_space((p->width)));
	return (count);
}

int	flags_width(int count, char *str, t_flags *p)
{
	count = 0;
	if (p->width != 0 && p->pr == 0)
		count += flags_all_s_help2(count, &str, p);
	else
		count = (ft_putstr_space((p->width)));
	return (count);
}

int	flags_precision(int count, char *str, t_flags *p)
{
	count = 0;
	if (p->precision >= 0 && p->width == 0)
		count += flags_all_s_help3(count, &str, p);
	else if (p->width == 0 && p->pr == 0)
	{
		if (str == NULL)
			str = "(null)";
		count = ft_putstr(str);
	}
	return (count);
}
