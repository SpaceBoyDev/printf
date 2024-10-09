/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:42:49 by dario             #+#    #+#             */
/*   Updated: 2024/10/09 19:19:30 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
void	ft_putchar_fd(char c, int *len);
void	ft_putstr_fd(char *s, int *len);
void	ft_printhexa(size_t num, char *hex_digits, int *len);
void	ft_putnbr_fd(int n, int *len);
void	ft_putunsigned_fd(int n, int *len);

#endif
