/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_len_un.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:47:36 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/20 14:48:22 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_itoa_len_un(unsigned int n)
{
	char			*str;
	int				i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	if (!(str = (char *)malloc((i) + sizeof(char))))
		return (0);
	return (i);
}
