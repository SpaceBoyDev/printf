/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:39:44 by dario             #+#    #+#             */
/*   Updated: 2024/10/09 20:53:21 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int				printf_size;
	int				ft_printf_size;
	int				n = -23455;
	unsigned int	un = 345789;
	char			c = 'c';
	char			s[] = "string";


	printf("\nChecking printf...\n");
	printf_size = printf("\nChar -> %c\nString -> %s\nPointer -> %p\nDecimal -> %d\nInt -> %i\nUnsigned -> %u\nhexa -> %x\nHEXA -> %X\n", c, s, &n, n, n , n, un, un);
	ft_printf("\nChecking ft_printf...\n");
	ft_printf_size = ft_printf("\nChar -> %c\nString -> %s\nPointer -> %p\nDecimal -> %d\nInt -> %i\nUnsigned -> %u\nhexa -> %x\nHEXA -> %X\n", c, s, &n, n, n , n, un, un);
	printf("\n\nprintf_size -> %d\nft_printf_size -> %d\n", printf_size, ft_printf_size);
	return (0);
}
