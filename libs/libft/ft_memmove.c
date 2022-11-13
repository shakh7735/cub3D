/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:44:12 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/12 18:52:33 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ds;
	char	*sr;

	ds = dst;
	sr = (char *)src;
	if (sr < ds)
	{
		while (len--)
			*(ds + len) = *(sr + len);
	}
	else
		while (len--)
			*ds++ = *sr++;
	return (dst);
}
