/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_all_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:42:20 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_width_c(int count, int str, t_flags *p)
{
	count = 0;
	if (p->width != 0)
	{
		if (p->minus != 0)
			count = (ft_putchar_count(str, count)
			+ ft_putstr_space((p->width) - 1));
		else
			count = (ft_putstr_space((p->width) - 1)
			+ ft_putchar_count(str, count));
	}
	else
		count = ft_putchar_count(str, count);
	return (count);
}
