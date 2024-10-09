/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:07:35 by dario             #+#    #+#             */
/*   Updated: 2024/10/09 20:43:01 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexa(size_t num, char *hex_digits, int *len)
{
	if (num >= 16)
		ft_printhexa((num / 16), hex_digits, len);
	ft_putchar(hex_digits[num % 16], len);
}

void	ft_putnbr(int n, int *len)
{
	char	num;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, len);
	num = n % 10 + '0';
	ft_putchar(num, len);
}

void	ft_putunsigned(unsigned int n, int *len)
{
	unsigned int	num;

	num = 0;
	if (n >= 10)
		ft_putunsigned(n / 10, len);
	num = n % 10 + '0';
	ft_putchar(num, len);
}
