/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <akazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 01:06:25 by akazarya          #+#    #+#             */
/*   Updated: 2022/04/08 20:57:24 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_zerox(char x)
{
	return (write(1, "0", 1) + write(1, &x, 1));
}

int	ft_putnbr_hex(unsigned long long nb, char a)
{
	int	nbr_out[20];
	int	print_len;
	int	i;

	print_len = 0;
	i = 0;
	if (!nb)
		print_len += ft_putchar('0');
	while (nb)
	{
		nbr_out[i++] = nb % 16;
		nb = nb / 16;
	}
	while (--i >= 0)
	{
		if (nbr_out[i] > 9)
			print_len += ft_putchar(a + nbr_out[i] - 10);
		else
			print_len += ft_putchar(nbr_out[i] + '0');
	}
	return (print_len);
}

int	ft_puthex(t_flags *flags, unsigned int nu, char x)
{
	int				print_len;
	int				len;
	unsigned int	num;

	flags->type = 1;
	num = nu;
	len = 0;
	while (nu)
	{
		len++;
		nu = nu / 16;
	}
	print_len = flags_do_dot(flags, len, num);
	if (flags->sharp == 1 && num != 0)
		print_len += put_zerox(x);
	if (!num)
		len++;
	if (flags->dot)
		print_len += put_symbols(flags->precision, len, '0');
	if (!flags->dot || flags->precision || num)
		print_len += ft_putnbr_hex(num, x - 23);
	return (print_len);
}

int	ft_putptr(t_flags *flags, unsigned long long p)
{
	unsigned long long	point;
	int					print_len;
	int					len;

	flags->type = 1;
	flags->sharp = 1;
	point = p;
	len = 0;
	while (point)
	{
		len++;
		point = point / 16;
	}
	print_len = flags_do_dot(flags, len, p);
	print_len += put_zerox('x');
	if (!p)
		len++;
	if (flags->dot)
		print_len += put_symbols(flags->precision, len, '0');
	print_len += ft_putnbr_hex(p, 'a');
	return (print_len);
}
