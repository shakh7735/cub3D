/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:45:37 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 17:45:39 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map_loop(int *player, int *i)
{
	int	j;

	j = -1;
	while (map.maps[*i][++j])
	{
		if (map.maps[*i][j] != '0' && map.maps[*i][j] != '1'
			&& map.maps[*i][j] != ' ' && map.maps[*i][j] != 'W'
			&& map.maps[*i][j] != 'E' && map.maps[*i][j] != 'N'
		&& map.maps[*i][j] != 'S' && map.maps[*i][j] != 'C')
			put_error("Incorrect map (other characters)");
		else if (map.maps[*i][j] != '0' && map.maps[*i][j] != '1'
			&& map.maps[*i][j] != ' ' && map.maps[*i][j] != 'C')
			(*player)++;
		if (map.maps[*i][j] == 'C')
			map.coins++;
	}
}

void	check_map(void)
{
	int	i;
	int	player;

	if (!map.png_no || !map.png_so || !map.png_we || !map.png_ea \
	|| map.collor_f == -1 || map.collor_c == -1)
		put_error("not valid args");
	if (map.y < 3 || map.x < 3)
		put_error("Incorrect map (size)");
	player = 0;
	map.coins = 0;
	map.coll_coins = 0;
	i = -1;
	while (map.maps[++i])
		check_map_loop(&player, &i);
	if (!player || player > 1)
		put_error("Incorrect map (player count)");
}

void	get_position_if(int i, int j)
{
	player.x = Size * (i + 0.5);
	player.y = Size * (j + 0.5);
	if (map.maps[j][i] == 'E')
		player.view = 0;
	else if (map.maps[j][i] == 'N')
		player.view = 90;
	else if (map.maps[j][i] == 'W')
		player.view = 180;
	else if (map.maps[j][i] == 'S')
		player.view = 270;
	map.maps[j][i] = '0';
}

void	get_positions(void)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map.y)
	{
		i = -1;
		while (++i < map.x)
		{
			if (map.maps[j][i] == 'N' || map.maps[j][i] == 'S' \
			|| map.maps[j][i] == 'E' || map.maps[j][i] == 'W')
				get_position_if(i, j);
		}
	}
}
