/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <akazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 01:03:17 by akazarya          #+#    #+#             */
/*   Updated: 2022/04/09 03:57:21 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags_sum(t_flags *flags)
{
	return (flags->flag_minus + flags->flag_zero + flags->dot + flags->sharp
		+ flags->space + flags->plus);
}

int	do_flags_end(t_flags *flags, int print_len)
{
	if (flags->flag_minus == 1)
		print_len += put_symbols(flags->width, print_len, ' ');
	return (print_len);
}

int	put_symbols(int width, int print_len, char c)
{
	int	i;
	int	num;

	num = 0;
	i = print_len - 1;
	while (++i < width)
		num += write(1, &c, 1);
	return (num);
}
