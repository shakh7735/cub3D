/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 01:05:59 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/13 00:13:01 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*st1;
	unsigned const char	*st2;
	int					i;
	int					num;

	st1 = s1;
	st2 = s2;
	i = 0;
	num = 0;
	while (n--)
	{
		if (st1[i] != st2[i])
		{
			num = st1[i] - st2[i];
			break ;
		}
		i++;
	}
	return (num);
}
