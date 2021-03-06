/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:31:05 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/08/27 11:37:43 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	long nb2;

	nb2 = nb;
	if (nb < 0)
	{
		nb2 = -nb2;
		ft_putchar('-');
	}
	if (nb2 >= 10)
		ft_putnbr(nb2 / 10);
	ft_putchar(nb2 % 10 + '0');
}
