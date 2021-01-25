/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:29:00 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/18 18:42:27 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	s = (char *)malloc((i + 1) * sizeof(char));
	if (s == 0)
		return (0);
	while (s1[j] != '\0')
	{
		s[j] = s1[j];
		j++;
	}
	s[i] = '\0';
	return (s);
}
