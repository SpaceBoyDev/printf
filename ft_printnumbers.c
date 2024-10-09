/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:07:35 by dario             #+#    #+#             */
/*   Updated: 2024/10/09 19:21:58 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printhexa(size_t num, char *hex_digits, int *len)
{
	if (num >= 16)
		ft_printhexa((num / 16), hex_digits, len);
	ft_putchar_fd(hex_digits[num % 16], len);
}

void	ft_putnbr_fd(int n, int *len)
{
	char	num;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', len);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, len);
	num = n % 10 + '0';
	ft_putchar_fd(num, len);
}

void	ft_putunsigned_fd(int n, int *len)
{
	char	num;

	if (n < 0)
	{
		write(1, "4294967088", 11);
		return ;
	}
	if (n > 9)
		ft_putunsigned_fd(n / 10, len);
	num = n % 10 + '0';
	ft_putchar_fd(num, len);
}
