/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:42:15 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/18 13:45:34 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	len;
	char			*s3;
	unsigned int	len1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * len + 1);
	if (!s3)
		return (NULL);
	ft_strcpy(s3, (char *)s1);
	s3 += len1;
	ft_strcpy(s3, (char *)s2);
	return (s3 - len1);
}
