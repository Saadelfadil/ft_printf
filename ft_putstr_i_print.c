/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_i_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:13:54 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/14 21:45:33 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_i_print(char *str, int len)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	if (str == NULL)
		str = "(null)";
	while (*str != '\0' && i < len)
	{
		count += ft_putchar(*str);
		str++;
		i++;
	}
	return (count);
}
