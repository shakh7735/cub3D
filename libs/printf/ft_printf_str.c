/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <akazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:35:30 by akazarya          #+#    #+#             */
/*   Updated: 2022/04/08 20:51:09 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	flag_putchar(t_flags *flags, char c)
{
	int	print_len;

	print_len = flags_do_str(flags, 1);
	if (flags->dot && !flags->flag_minus && !flags->flag_zero)
		print_len += put_symbols(flags->width, print_len, ' ');
	ft_putchar(c);
	return (print_len);
}

int	ft_putstr(t_flags *flags, char *s)
{
	int	print_len;
	int	len;

	print_len = 0;
	len = ft_strlen(s);
	if (!s)
		len = 6;
	if (flags->dot && len > flags->precision)
		len = flags->precision;
	print_len = flags_do_str(flags, len);
	if (flags->dot && !flags->flag_minus && !flags->flag_zero)
		print_len += put_symbols(flags->width, len, ' ');
	if (!s)
		write(1, "(null)", len);
	else
		write(1, s, len);
	return (print_len);
}
