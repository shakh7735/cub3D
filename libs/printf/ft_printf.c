/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <akazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:14:43 by akazarya          #+#    #+#             */
/*   Updated: 2022/04/11 22:18:09 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkpercent(t_flags	*flags, va_list args, const char c, int print_len)
{
	if (c == 'c')
		print_len += flag_putchar(flags, va_arg (args, int));
	else if (c == 's')
		print_len += ft_putstr(flags, va_arg (args, char *));
	else if (c == 'p')
		print_len += ft_putptr(flags, va_arg (args, unsigned long long));
	else if (c == 'd' || c == 'i')
		print_len += ft_putnbr(flags, va_arg (args, int));
	else if (c == 'u')
		print_len += ft_putnbr_unsigned(flags, va_arg (args, unsigned int));
	else if (c == 'x' || c == 'X')
		print_len += ft_puthex(flags, va_arg (args, unsigned int), c);
	else
	{
		flags->dot = 0;
		flags->sharp = 0;
		print_len += flags_do_num(flags, 1);
		if (c == '%')
			print_len += write (1, "%", 1);
	}
	print_len = do_flags_end(flags, print_len);
	return (print_len);
}

void	get_width(const char *str, int *i, int *flag_dot)
{
	char	num[20];
	int		j;

	j = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num[j++] = str[*i];
		*i += 1;
	}
	num[j] = 0;
	*i -= 1;
	*flag_dot = ft_atoi(num);
}

int	ft_goback(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}

int	ft_printf_str(const char *str, va_list args, int print_len)
{
	int		i;
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (-1);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			flags_null(flags);
			while (check_flags(flags, str, &i))
				i++;
			print_len += ft_checkpercent(flags, args, str[i], 0);
			i -= ft_goback (str[i]);
		}
		else
			print_len += ft_putchar(str[i]);
	}
	free(flags);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		print_len;
	va_list	args;

	va_start(args, str);
	print_len = ft_printf_str(str, args, 0);
	va_end(args);
	return (print_len);
}

// int	main()
// {
// 	char *arg = "	printf: \"%0d%\" ";
// 	// char *set = "Arman";
// 	// char set = 48;
// 	long long	set = -999;
// 	printf("   size: %d;\n",    printf(arg, set));
// 	printf("ft_size: %d;\n", ft_printf(arg, set));
// }
