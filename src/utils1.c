/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:07:10 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 18:07:12 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_error(char *str)
{
	printf("Error: %s\n", str);
	exit(1);
}

int	close_prog(void)
{
	mlx_destroy_window(data.mlx, data.win);
	free(map.maps);
	exit(0);
	return (0);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

void	free_mtx(char **buff)
{
	int	i;

	i = -1;
	while (buff[++i])
		free(buff[i]);
	free(buff);
}

int	get_num(const char *str)
{
	int			i;
	long int	num;

	num = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			put_error("not valid rgb args");
		else
			num = num * 10 + str[i] - 48;
		if (num > 255)
			put_error("not valid rgb range [0, 255]");
		i++;
	}
	return (num);
}
