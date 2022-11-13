/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:45:51 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 17:45:54 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	flood_make(char **tab, int x, int y)
{
	if (x < 0 || y < 0 || !tab[y] || !tab[y][x] || tab[y][x] == ' ')
		put_error("Incorrect map (unclosed map)");
	else if (tab[y][x] == '1' || tab[y][x] == 'F')
		return ;
	else
		tab[y][x] = 'F';
	flood_make(tab, x + 1, y);
	flood_make(tab, x - 1, y);
	flood_make(tab, x, y + 1);
	flood_make(tab, x, y - 1);
}

void	ckeck_map_flood(void)
{
	char	**tab;
	int		i;
	int		j;

	tab = malloc(sizeof(char *) * (map.y + 1));
	i = -1;
	while (map.maps[++i])
		tab[i] = ft_strdup(map.maps[i]);
	tab[i] = NULL;
	j = -1;
	while (tab[++j])
	{
		i = -1;
		while (tab[j][++i])
			if (tab[j][i] != '1' && tab[j][i] != ' ' && tab[j][i] != 'F')
				flood_make(tab, i, j);
	}
	free_mtx(tab);
}

void	check_line(char *line)
{
	int	i;
	int	id;

	if (!line)
		put_error("Incorrect map (NULL)");
	i = 0;
	id = 0;
	while (line[i] && id != 7)
	{
		while (line[i] == '\n')
			i++;
		while (line[i] && line[i] != '\n')
			i++;
		id++;
	}
	while (line[i])
		if (line[i++] == '\n' && line[i] == '\n')
			put_error("Incorrect map (newlines)");
}

char	*my_ft_strjoin(char const *s1, char *s2)
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
	if (s2 && s2[0])
		free(s2);
	return (str);
}
