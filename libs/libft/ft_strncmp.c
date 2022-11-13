/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:18:29 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/11 02:25:06 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (n--)
	{
		if (s1[i] != s2[i])
		{
			num = s1[i] - s2[i];
			break ;
		}
		i++;
	}
	return (num);
}
