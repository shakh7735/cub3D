/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:40:49 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/14 22:44:10 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_beginsize(const char *s, char const *set)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	while (s[i] && set[k])
		if (s[i] == set[k++])
			k = 0 * i++;
	return (i);
}

static int	ft_endsize(const char *s, char const *set)
{
	unsigned int	i;
	unsigned int	k;

	i = ft_strlen(s);
	k = 0;
	while (i && set[k])
		if (s[i - 1] == set[k++])
			k = 0 * i--;
	return (ft_strlen(s) - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		size;
	int		begin;
	int		end;

	size = ft_strlen(s1);
	begin = ft_beginsize(s1, set);
	end = ft_endsize(s1, set);
	if (size - begin - end > 0)
		str = ft_substr(s1, begin, size - begin - end);
	else
		str = ft_substr(s1, size, 1);
	return (str);
}
