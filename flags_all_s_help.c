/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_all_s_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 07:08:11 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flags_all_s_help1_1(int count, char **str, t_flags *p)
{
	if (p->precision > 0)
	{
		if (p->precision >= ft_strlen(*str))
			count = (ft_putstr_space((p->width)
			- ft_strlen(*str)) + ft_putstr(*str));
		else if (p->precision < ft_strlen(*str))
			count = (ft_putstr_space((p->width) - (p->precision))
			+ ft_putstr_i_print(*str, (p->precision)));
	}
	return (count);
}

int			flags_all_s_help1(int count, char **str, t_flags *p)
{
	if (*str == NULL)
		*str = "(null)";
	if (p->minus != 0)
	{
		if (p->precision > 0)
		{
			if (p->precision >= ft_strlen(*str))
				count = (ft_putstr(*str) + ft_putstr_space((p->width)
				- ft_strlen(*str)));
			else if (p->precision < ft_strlen(*str))
				count = (ft_putstr_i_print(*str, (p->precision))
				+ ft_putstr_space((p->width) - (p->precision)));
		}
	}
	else
		count += flags_all_s_help1_1(count, &*str, p);
	return (count);
}

int			flags_all_s_help2(int count, char **str, t_flags *p)
{
	if (*str == NULL)
		*str = "(null)";
	if (p->minus != 0)
	{
		if (p->width > ft_strlen(*str))
			count = (ft_putstr(*str) + ft_putstr_space((p->width)
			- ft_strlen(*str)));
		else
			count = (ft_putstr_space((p->width) -
			ft_strlen(*str)) + ft_putstr(*str));
	}
	else
	{
		if (p->width > ft_strlen(*str))
			count = (ft_putstr_space((p->width) -
			ft_strlen(*str)) + ft_putstr(*str));
		else
			count = (ft_putstr(*str) + ft_putstr_space((p->width)
			- ft_strlen(*str)));
	}
	return (count);
}

int			flags_all_s_help3(int count, char **str, t_flags *p)
{
	if (*str == NULL)
		*str = "(null)";
	if (p->minus != 0)
	{
		if (p->precision > 0)
		{
			if (p->precision >= ft_strlen(*str))
				count = (ft_putstr(*str) + ft_putstr_space((p->width)
				- ft_strlen(*str)));
			else if (p->precision < ft_strlen(*str))
				count = (ft_putstr_space((p->width) - (p->precision))
				+ ft_putstr_i_print(*str, (p->precision)));
		}
	}
	else
	{
		if (p->precision > 0)
		{
			if (p->precision >= ft_strlen(*str))
				count = ft_putstr(*str);
			else if (p->precision < ft_strlen(*str))
				count = (ft_putstr_i_print(*str, (p->precision)));
		}
	}
	return (count);
}
