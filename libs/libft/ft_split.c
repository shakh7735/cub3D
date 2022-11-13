/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:02:59 by akazarya          #+#    #+#             */
/*   Updated: 2022/03/13 00:13:35 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(const char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	return (j);
}

static int	ft_msize(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			j++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**str;
	int		i;

	i = 0;
	words = ft_msize(s, c);
	str = malloc(8 * (words + 1));
	if (!str)
		return (NULL);
	str[words] = NULL;
	while (words--)
	{
		while (*s == c && *s)
			s++;
		str[i] = ft_substr(s, 0, ft_wordlen(s, c));
		if (!str[i])
			return (NULL);
		s = s + ft_wordlen(s, c);
		i++;
	}
	return (str);
}
