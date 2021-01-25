/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 12:35:32 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/10 22:17:17 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	char	t;
	int		l;
	int		i;

	l = 0;
	while (str[l] != '\0')
	{
		l++;
	}
	i = 0;
	while (i < l / 2)
	{
		t = str[i];
		str[i] = str[l - i - 1];
		str[l - i - 1] = t;
		i++;
	}
	return (str);
}
