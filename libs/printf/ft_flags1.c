/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <akazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 01:03:17 by akazarya          #+#    #+#             */
/*   Updated: 2022/04/09 04:29:07 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_null(t_flags	*flags)
{
	flags->flag_minus = 0;
	flags->flag_zero = 0;
	flags->dot = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->num_m = 0;
	flags->type = 0;
}

int	check_flags(t_flags *flags, const char *str, int *i)
{
	if (str[*i] >= '0' && str[*i] <= '9' && str[*i -1] == '.')
		get_width(str, i, &flags->precision);
	else if (str[*i] > '0' && str[*i] <= '9')
		get_width(str, i, &flags->width);
	else
	{
		if (str[*i] == '-')
			flags->flag_minus = 1;
		else if (str[*i] == '0')
			flags->flag_zero = 1;
		else if (str[*i] == '#')
			flags->sharp = 1;
		else if (str[*i] == ' ')
			flags->space = 1;
		else if (str[*i] == '+')
			flags->plus = 1;
		else if (str[*i] == '.')
			flags->dot = 1;
		else
			return (0);
	}
	return (1);
}

int	flags_do_dot(t_flags *flags, int print_len, int num)
{
	int	len;

	if (!num)
		print_len++;
	len = 0;
	if (flags->dot && !flags->flag_minus)
	{
		if (print_len > flags->precision && num)
			flags->precision = print_len;
		if (flags->plus == 2 && !flags->num_m)
			len += put_symbols(flags->width, flags->precision + 1, ' ');
		if (flags_sum(flags) == 1 || flags->flag_zero || flags->space
			|| (flags->sharp && !flags->flag_minus) || flags->plus == 1)
			len += put_symbols(flags->width,
					flags->precision + flags->sharp * 2 + flags->num_m, ' ');
		if (flags->space && flags->width <= flags->precision
			&& flags->type == 2)
			len += put_symbols(flags->precision + 1,
					flags->precision + flags->num_m, ' ');
	}
	len += flags_do_num(flags, print_len + len);
	if (flags->dot && flags->type != 1)
		len += put_symbols(flags->precision, print_len, '0');
	return (len);
}

int	flags_do_num(t_flags *flags, int print_len)
{
	int	len;

	len = 0;
	if ((((flags->sharp || flags ->space) && !flags->dot)
			&& !flags->flag_minus) || !flags_sum(flags))
		len += put_symbols(flags->width, print_len
				+ flags->sharp * 2 + flags->num_m, ' ');
	else if (flags->plus && !flags->dot && !flags->flag_minus)
		len += put_symbols(flags->width, print_len + flags->plus - 1, ' ');
	if (flags->plus == 2 && !flags->num_m)
		len += write (1, "+", 1);
	if (flags->num_m)
		len += ft_putchar('-');
	if (flags->space && !flags->dot && flags->width <= print_len
		&& flags->type == 2 && !flags->flag_minus)
		len += put_symbols(1, 0, ' ');
	if (flags->flag_zero && !flags->dot && !flags->flag_minus)
		len += put_symbols(flags->width, print_len + flags->num_m, '0');
	return (len);
}

int	flags_do_str(t_flags *flags, int print_len)
{
	int	len;

	len = print_len;
	if (!flags_sum(flags) || ((flags->space || flags->plus || flags->sharp)
			&& !flags->dot && !flags->flag_minus))
		len += put_symbols(flags->width, print_len, ' ');
	if (flags->flag_zero && !flags->flag_minus)
		len += put_symbols(flags->width, print_len, '0');
	return (len);
}
