/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:41:20 by dario             #+#    #+#             */
/*   Updated: 2024/10/09 20:42:55 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_selectcase(char format, va_list arg, int *len)
{
	if (format == 'c')
		ft_putchar(va_arg(arg, int), len);
	else if (format == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (format == 'p')
	{
		ft_putstr("0x", len);
		ft_printhexa(va_arg(arg, size_t), "0123456789abcdef", len);
	}
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(arg, int), len);
	else if (format == 'u')
		ft_putunsigned(va_arg(arg, unsigned int), len);
	else if (format == 'x')
		ft_printhexa(va_arg(arg, size_t), "0123456789abcdef", len);
	else if (format == 'X')
		ft_printhexa(va_arg(arg, size_t), "0123456789ABCDEF", len);
	else if (format == '%')
		ft_putchar('%', len);
}

int	ft_printf(char const *format, ...)
{
	int		len;
	va_list	arg_list;

	len = 0;
	va_start(arg_list, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			ft_selectcase(*format, arg_list, &len);
			++format;
		}
		else
		{
			write(1, format, 1);
			++format;
			++len;
		}
	}
	va_end(arg_list);
	return (len);
}
