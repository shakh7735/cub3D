/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <akazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:35:44 by akazarya          #+#    #+#             */
/*   Updated: 2022/04/08 21:02:38 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getnbr_unsigned(unsigned int nbr)
{
	if (nbr >= 10)
		return (ft_getnbr(nbr / 10) + ft_putchar(nbr % 10 + '0'));
	return (ft_putchar(nbr % 10 + '0'));
}

int	ft_putnbr_unsigned(t_flags	*flags, unsigned int nu)
{
	int				print_len;
	unsigned int	num;

	num = nu;
	print_len = 0;
	while (nu)
	{
		print_len++;
		if (nu < 10)
			break ;
		nu = nu / 10;
	}
	print_len = flags_do_dot(flags, print_len, num);
	if (!flags->dot || flags->precision || num)
		print_len += ft_getnbr_unsigned(num);
	return (print_len);
}

int	ft_getnbr(long long nbr)
{
	if (nbr >= 10)
		return (ft_getnbr(nbr / 10) + ft_putchar(nbr % 10 + '0'));
	return (ft_putchar(nbr % 10 + '0'));
}

int	ft_putnbr(t_flags *flags, int nu)
{
	int			print_len;
	long long	num;

	if (flags->plus)
		flags->plus = 2;
	flags->type = 2;
	num = nu;
	print_len = 0;
	while (nu)
	{
		print_len++;
		nu = nu / 10;
	}
	if (num < 0)
	{
		flags->num_m = 1;
		num = -num;
	}
	if (flags->space && !flags->dot && flags->width <= 1)
		flags->width = print_len + 1;
	print_len = flags_do_dot(flags, print_len, num);
	if (!flags->dot || flags->precision || num)
		print_len += ft_getnbr(num);
	return (print_len);
}
