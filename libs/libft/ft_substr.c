/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:09:19 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/13 00:16:08 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	size_t			i;
	unsigned int	size;
	unsigned int	m;

	size = 0;
	while (s[size])
		size++;
	if (size + 1 < start)
		m = 1;
	else if (size - start + 1 > len)
		m = len + 1;
	else
		m = size - start + 1;
	s1 = malloc(m);
	if (!s1)
		return (NULL);
	i = 0;
	while (i < len && start + i < size)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
