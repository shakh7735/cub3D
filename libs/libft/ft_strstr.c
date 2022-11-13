/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:45:30 by akazarya          #+#    #+#             */
/*   Updated: 2022/02/16 20:03:09 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j])
			if (to_find[j++ + 1] == '\0')
				return (&str[i]);
	}
	return (0);
}
