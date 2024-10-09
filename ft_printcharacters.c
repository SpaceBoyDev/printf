/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcharacters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:18:22 by dario             #+#    #+#             */
/*   Updated: 2024/10/09 20:43:10 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *len)
{
	if (!s)
		ft_putstr("(null)", len);
	while (*s)
	{
		ft_putchar(*s, len);
		++s;
	}
}

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	++(*len);
}
