/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fadi <sel-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:05:18 by sel-fadi          #+#    #+#             */
/*   Updated: 2019/11/21 15:14:22 by sel-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					check_conversion(const char **format,
int count, va_list vlist, t_flags *p)
{
	if (*format[0] == '%')
		count += print_modulo(count, *format[0], p);
	else if (*format[0] == 's')
		count += print_s(count, vlist, p);
	else if (*format[0] == 'c')
		count += print_c(count, vlist, p);
	else if (*format[0] == 'd' || *format[0] == 'i')
		count += print_d(count, vlist, p);
	else if (*format[0] == 'u')
		count += print_u(count, vlist, p);
	else if (*format[0] == 'x')
		count += print_x(count, vlist, p);
	else if (*format[0] == 'X')
		count += print_x_x(count, vlist, p);
	else if (*format[0] == 'p')
		count += print_p(count, vlist, p);
	format[0] += 1;
	return (count);
}

static void			initialisation_struct(t_flags **my_struct)
{
	(*my_struct)->zero = 0;
	(*my_struct)->minus = 0;
	(*my_struct)->width = 0;
	(*my_struct)->precision = -1;
	(*my_struct)->pr = 0;
}

t_flags				*check_flags(const char **format, va_list vlist)
{
	t_flags	*p;
	int		i;
	int		j;
	char	first;

	i = 1;
	j = 1;
	p = malloc(sizeof(t_flags));
	initialisation_struct(&p);
	first = format[0][0];
	while (*format[0] != '.' && ft_isalpha(*format[0]) == 0
	&& *format[0] != '%')
	{
		check_flags_help1(format, vlist, p, first);
		if (*format[0] >= '0' && *format[0] <= '9' && i != 0)
		{
			p->width = atoi(format[0]);
			i = 0;
		}
		format[0] += 1;
	}
	check_flags_help2(format, vlist, p);
	return (p);
}

static int			check_format(const char *format, va_list vlist)
{
	int		count;
	t_flags	*p;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			p = check_flags(&format, vlist);
			count += flags_print(&format, count, vlist, p);
		}
		else
		{
			count += ft_putchar(*format);
			format++;
		}
	}
	return (count);
}

int					ft_printf(const char *format, ...)
{
	va_list vlist;
	int		count;

	count = 0;
	va_start(vlist, format);
	count += check_format(format, vlist);
	va_end(vlist);
	return (count);
}
