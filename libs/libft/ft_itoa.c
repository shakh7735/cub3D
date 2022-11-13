/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:50:34 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/14 23:42:12 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_divint(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_itoanum(long int nbr, char *tab, int len)
{
	if (nbr >= 0)
		len--;
	else
		nbr = -nbr;
	while (nbr > 9)
	{
		tab[len--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (nbr < 10)
		tab[len] = nbr + '0';
}

char	*ft_itoa(int n)
{
	char		*tab;
	int			i;
	int			len;
	long int	nbr;

	i = 0;
	nbr = n;
	len = ft_divint(nbr);
	if (n < 0)
		tab = malloc(len + 2);
	else
		tab = malloc(len + 1);
	if (!tab)
		return (NULL);
	if (nbr < 0)
		tab[i++] = '-';
	ft_itoanum(nbr, tab, len);
	tab[len + i] = '\0';
	return (tab);
}
