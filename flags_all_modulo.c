/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_all_modulo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:53:19 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_width_modulo(int count, char str, t_flags *p)
{
	count = 0;
	if (p->width != 0 && p->zero == 0)
	{
		if (p->minus != 0)
			count = (ft_putchar(str) + ft_putstr_space((p->width) - 1));
		else
			count = (ft_putstr_space((p->width) - 1) + ft_putchar(str));
	}
	else if (p->width != 0 && p->zero != 0)
	{
		if (p->minus != 0)
			count = (ft_putchar(str) + ft_putstr_zero((p->width) - 1));
		else
			count = (ft_putstr_zero((p->width) - 1) + ft_putchar(str));
	}
	else
		count = ft_putchar(str);
	return (count);
}
