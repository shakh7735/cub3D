/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:55:05 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/13 20:30:39 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*ds;
	const char	*sr;

	ds = dst;
	sr = src;
	while (n--)
	{
		*ds++ = *sr;
		if (*sr++ == (unsigned char)c)
			return ((void *)ds);
	}
	return (NULL);
}
