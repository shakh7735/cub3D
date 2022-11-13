/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <akazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:36:22 by akazarya          #+#    #+#             */
/*   Updated: 2022/04/09 03:55:23 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int		flag_minus;
	int		flag_zero;
	int		dot;
	int		sharp;
	int		space;
	int		plus;
	int		width;
	int		precision;
	int		num_m;
	int		type;
}				t_flags;

int		ft_printf(const char *str, ...);
int		ft_printf_str(const char *str, va_list args, int print_len);
int		put_symbols(int width, int print_len, char c);
int		do_flags_end(t_flags *flags, int print_len);
int		ft_checkpercent(t_flags	*flags, va_list args, const char c,
			int print_len);
void	get_width(const char *str, int *i, int *flag_dot);
int		ft_goback(char c);
int		ft_getnbr_unsigned(unsigned int nbr);
int		ft_putnbr_unsigned(t_flags	*flags, unsigned int nu);
int		ft_putptr(t_flags *flags, unsigned long long p);
int		ft_getnbr(long long nbr);
int		ft_putnbr(t_flags *flags, int nu);
int		put_zerox(char x);
int		ft_putnbr_hex(unsigned long long nb, char a);
int		ft_puthex(t_flags *flags, unsigned int nu, char x);
int		ft_putchar(char c);
int		flag_putchar(t_flags *flags, char c);
int		flags_do_str(t_flags *flags, int print_len);
int		ft_putstr(t_flags *flags, char *s);
int		flags_do_num(t_flags *flags, int print_len);
int		flags_do_dot(t_flags *flags, int print_len, int num);
void	flags_null(t_flags	*flags);
int		check_flags(t_flags *flags, const char *str, int *i);
int		flags_sum(t_flags *flags);

#endif
