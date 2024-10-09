/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:41:20 by dario             #+#    #+#             */
/*   Updated: 2024/10/09 19:35:53 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_selectcase(char format, va_list arg, int *len)
{
	if (format == 'c')
		ft_putchar_fd(va_arg(arg, int), len);
	else if (format == 's')
		ft_putstr_fd(va_arg(arg, char *), len);
	else if (format == 'p')
	{
		write(1, "0x", 2);
		ft_printhexa(va_arg(arg, size_t), "0123456789abcdef", len);
	}
	else if (format == 'd' || format == 'i')
		ft_putnbr_fd(va_arg(arg, int), len);
	else if (format == 'u')
		ft_putunsigned_fd(va_arg(arg, unsigned int), len);
	else if (format == 'x')
		ft_printhexa(va_arg(arg, size_t), "0123456789abcdef", len);
	else if (format == 'X')
		ft_printhexa(va_arg(arg, size_t), "0123456789ABCDEF", len);
	else if (format == '%')
		ft_putchar_fd('%', len);
}

int	ft_printf(char const *format, ...)
{
	int	len;
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
		}
	}
	va_end(arg_list);
	return (len);
}

int	main(void)
{
	int				printf_size;
	int				ft_printf_size;
	int				n = -2345;
	unsigned int	un = 345789;
	char			c = 'c';
	char			s[] = "string";


	printf("\nChecking printf...\n");
	printf_size = printf("\nChar -> %c\nString -> %s\nPointer -> %p\nDecimal -> %d\nInt -> %i\nUnsigned -> %u\nhexa -> %x\nHEXA -> %X", c, s, &n, n, n , n, un, un);
	ft_printf_size = ft_printf("\nChar -> %c\nString -> %s\nPointer -> %p\nDecimal -> %d\nInt -> %i\nUnsigned -> %u\nhexa -> %x\nHEXA -> %X", c, s, &n, n, n , n, un, un);
	printf("printf_size -> %d\nft_printf_size -> %d", printf_size, ft_printf_size);
	return (0);
}
