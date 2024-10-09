/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcharacters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:18:22 by dario             #+#    #+#             */
/*   Updated: 2024/10/09 19:36:39 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_fd(char *s, int *len)
{
	if (!s)
		ft_putstr_fd("(null)", len);
	while (*s)
	{
		ft_putchar_fd(*s, len);
		++s;
	}
}

void	ft_putchar_fd(char c, int *len)
{
	write(1, &c, 1);
	++(*len);
}
