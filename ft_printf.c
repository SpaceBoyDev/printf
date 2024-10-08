/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:41:20 by dario             #+#    #+#             */
/*   Updated: 2024/10/08 20:07:30 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		++s;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static size_t	ft_countvariables(char const *format)
{
	size_t	var_count;

	var_count = 0;
	while(*format)
	{
		if (*format == '%')
			++var_count;
		++format;
	}
	return (var_count);
}

static void	ft_selectcase(char format, va_list arg)
{
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		printf("Caso char");
	}
	else if (format == 's')
		ft_putstr_fd(va_arg(arg, char *), 1);
}

int	ft_printf(char const *format, ...)
{
	va_list	arg_list;
	size_t	var_count;

	va_start(arg_list, format);

	while (*format)
	{
		if (*format == '%')
		{
			++format;
			ft_selectcase(*format, arg_list);
			++format;
		}
		else
		{
			write(1, format, 1);
			++format;
		}
	}
	return (0);
}

int	main(void)
{
	size_t		n = 5;
	char		c = '(';
	char		s[] = "CARAMBOLOIcadas 87093";
	ft_printf("\nEl char es %c y el string es %s\n", c, s);
	return (0);
}
