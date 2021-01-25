/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_modulo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:47:48 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 14:50:44 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_modulo(int count, char str, t_flags *p)
{
	count = 0;
	str = '%';
	if (p->width || p->width == 0)
		return (count += flags_width_modulo(count, str, p));
	return (count);
}
