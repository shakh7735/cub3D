/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 01:40:15 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/11 01:53:36 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	if (dstsize <= j)
		return (ft_strlen(src) + dstsize);
	while (j + 1 < dstsize && src[i])
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (ft_strlen(&src[i]) + ft_strlen(dst));
}
