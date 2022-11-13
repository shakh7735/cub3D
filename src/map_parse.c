/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:29:25 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 17:29:27 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_args_value(char **arg)
{
	if (!arg[0] || !arg[1] || arg[2])
		put_error("not valid args");
	if (!ft_strcmp(arg[0], "NO") && !map.png_no)
		map.png_no = ft_strdup(arg[1]);
	else if (!ft_strcmp(arg[0], "SO") && !map.png_so)
		map.png_so = ft_strdup(arg[1]);
	else if (!ft_strcmp(arg[0], "WE") && !map.png_we)
		map.png_we = ft_strdup(arg[1]);
	else if (!ft_strcmp(arg[0], "EA") && !map.png_ea)
		map.png_ea = ft_strdup(arg[1]);
	else if (!ft_strcmp(arg[0], "F") && map.collor_f == -1)
		map.collor_f = get_rgb(arg[1]);
	else if (!ft_strcmp(arg[0], "C") && map.collor_c == -1)
		map.collor_c = get_rgb(arg[1]);
	else
		put_error("not valid args");
}

void	get_map_value(char **temp)
{
	int	j;
	int	i;

	map.x = 0;
	map.y = -1;
	while (temp[++map.y])
		if (map.x < (int)ft_strlen(temp[map.y]))
			map.x = (int)ft_strlen(temp[map.y]);
	map.maps = malloc(sizeof(char *) * (map.y + 1));
	i = -1;
	while (temp[++i])
	{
		map.maps[i] = malloc(sizeof(char) * (map.x + 1));
		j = -1;
		while (temp[i][++j])
			map.maps[i][j] = temp[i][j];
		while (j < map.x)
			map.maps[i][j++] = ' ';
		map.maps[i][j] = '\0';
	}
	map.maps[i] = NULL;
}

void	get_images_and_map(char **temp)
{
	int		i;
	char	**arg;

	map.collor_f = -1;
	map.collor_c = -1;
	i = -1;
	while (temp[++i] && i < 6)
	{
		arg = ft_split(temp[i], ' ');
		if (arg)
			get_args_value(arg);
		free_mtx(arg);
	}
	get_map_value(&temp[i]);
	check_map();
	ckeck_map_flood();
	get_positions();
}

void	get_map(char *filename)
{
	int		fd;
	char	*line;
	char	*buff;
	char	**temp;

	fd = open(filename, O_RDONLY);
	// if (fd == -1)
	// 	put_error("Bad file discriptor of map");
	line = NULL;
	buff = get_next_line(fd);
	while (buff)
	{
		line = ft_strjoin_free(line, buff);
		free (buff);
		buff = get_next_line(fd);
	}
	close(fd);
	temp = ft_split(line, '\n');
	check_line(line);
	free(line);
	get_images_and_map(temp);
	free_mtx(temp);
}
