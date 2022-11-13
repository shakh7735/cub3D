/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:54:32 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/19 17:42:19 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_rec(int nb, int i)
{
	if (i * i == nb)
		return (i);
	if (i > nb / i)
		return (0);
	return (ft_sqrt_rec(nb, i + 1));
}

int	ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	return (ft_sqrt_rec(nb, 2));
}
